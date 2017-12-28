#!/usr/bin/env python
# GUI_robots.py 

'''
@author: Jesus Savage, UNAM-FI, 11-2014
adapted for ROS by: Daniel Vargas.
'''

# System Libraries
import os
import time
import sys

# TK Libraries
import Tkinter as tk
import tkFileDialog
import tkMessageBox
from Tkinter import *

# Math Libraries
import math
import random
random.seed(0)

#ROS Libraries
import rospy
from svg_ros.srv import *
from std_msgs.msg import String

# THREADS Libraries
import thread
import time
import threading
import Queue



#---------------------------------------------------------------------------------------
#	Global Variables
#-------------------------------------------------------------------------------------------

DIM_CANVAS_X = 400
DIM_CANVAS_Y = 400

flg_execute = 0
flag_thread = 0
flg_finish = 0
flag_over = 0

num_steps_ros = 1
s_ros = "blank"
#s_r = ["a", "b", "c", "d"]
s_r = range(1000)
index = 0
prev_index = 1


def callback_resize(event):
        global DIM_CANVAS_X
        global DIM_CANVAS_Y
        global gui_planner

        if event.widget != planner:
                return

        DIM_CANVAS_X = event.width-2
        DIM_CANVAS_Y = event.height-2
        C.config(width=event.width-2, height=event.height-2)
        gui_planner.read_file_map(0)



class PLANNER(object):
   

	delay = 0.0
	num_sensors = 8
	range_angle = 0.2
	start_angle = -0.1

	PATH = 'path'
	robot_command = "../motion_planner/GoTo_State_Machine"

	mouse_1_x = 0.0
	mouse_1_y = 0.0
	mouse_2_x = 0.0
	mouse_2_y = 0.0
	mouse_3_x = 0.0
	mouse_3_y = 0.0

	polygons = []
	num_pol = 0

	pose_x = 4.0
	pose_y = 3.0
	pose_tetha = 0.0
	radio_robot = .03

	dim_x = 10.0
	dim_y = 10.0
	number_steps = 100

	event_mouse_3 = 0

	destination_x = 0
	destination_y = 0


	def callback_mouse_1(self,event):

			#print "clicked 1 at", event.x, event.y
			id = C.create_rectangle(event.x, event.y, event.x+1, event.y+1, fill= "black")
			x = (PLANNER.dim_x * event.x) / DIM_CANVAS_X
			y = (PLANNER.dim_y * (DIM_CANVAS_Y-event.y)) / DIM_CANVAS_Y
			#print "left button x ", x, " y ", y
			PLANNER.mouse_1_x = x
			PLANNER.mouse_1_y = y

			PLANNER.pose_tetha = float(self.robot_angle.get())
			PLANNER.pose_x=x
			PLANNER.pose_y=y

			self.plot_robot()


	def callback_mouse_2(self,event):

			#print "clicked 2 at", event.x, event.y
			id = C.create_rectangle(event.x, event.y, event.x+1, event.y+1, fill= "blue", outline='yellow')
			x = (PLANNER.dim_x * event.x) / DIM_CANVAS_X
			y = (PLANNER.dim_y * (DIM_CANVAS_Y-event.y)) / DIM_CANVAS_Y
			#print "middle button x ", x, " y ", y
			PLANNER.mouse_2_x = x
			PLANNER.mouse_2_y = y


	def callback_return(event):
			print "pressed", repr(event.char)
			


	def callback_mouse_3(self,event):
			global flg_execute
			global flg_finish
			global index


			#print "clicked 3 at", event.x, event.y
			id = C.create_rectangle(event.x, event.y, event.x+1, event.y+1, fill= "red", outline='red')
			x = (PLANNER.dim_x * event.x) / DIM_CANVAS_X
			y = (PLANNER.dim_y * (DIM_CANVAS_Y-event.y)) / DIM_CANVAS_Y
			#print "right button x ", x, " y ", y
			PLANNER.mouse_3_x = x
			PLANNER.mouse_3_y = y

			#if flg_execute == 1:
			if self.var_mov.get() == 0:
				C.update_idletasks()

			flg_finish = 0
			index = 0

			C.update_idletasks()
			PLANNER.event_mouse_3 = 1
			self.startPlotExecute()
			#print "oval x ",str(x)," y ",str(y)
			self.plot_oval(x,y)
			PLANNER.number_steps = self.number_steps.get()



	"""
		Callback that receives ROS messages
    		It prints motion_planner get_info
       		for real time plotting
       	"""
	def handle_mv_plot(self,req):
			global flag_thread
			global s_ros
			global s_r
			global index

        		s_ros=req.param
			index = index+1
			s_r[index] = s_ros
        		#print "new >> s_ros = %s"%(s_ros)
        		#print "s_r[",str(index),"] = ",s_r[index]
        		flag_thread = 1
			time.sleep(0)
			processing = "Processing GUI ",s_ros
        		#return MVServResponse(processing)
        		return MVServResponse("_")

	"""
		Function that it is triggered when motion_planner has ended
	"""
	def handle_over(self,req):
                        global flag_over

                        over_ros=req.over_flg
                        #print "new over >> over_ros = %d"%(over_ros)
                        flag_over = 1
                        time.sleep(0)
                        #return MVServResponse("_")
                        return OverSrvResponse(1)


	

	def Start_GUI(self):


			self.topLevelWindow = tk.Tk()
			self.topLevelWindow.wm_title('ROS_GUI_ROBOTS')

#________________________________________ BUTTONS''DEFINITIONS ______________________________________________________________________________________________________________________________

			# Plot Robot button
			self.RobotButton = tk.Button(self.topLevelWindow, width = 20, text = "Plot Previous Robot's Path", bg = 'green', activebackground = 'green', command = self.togglePlotRobot)
			self.countRobot = 0

			# Plot Sensor button
			self.ExecuteButton = tk.Button(self.topLevelWindow, width=20, text='Execute Robot Command ', bg = 'blue', activebackground = 'blue', command = self.startPlotExecute)
			self.countExecute = 0
			# Plot Map button
			self.MapButton = tk.Button(self.topLevelWindow, width = 20, text = 'Plot Map', bg = 'green', activebackground = 'green', command = self.togglePlotMap)
			self.countMap = 0
			# Plot Path button
			self.PathButton = tk.Button(self.topLevelWindow, width = 20, text = "Plot Previous Robot's Path", bg = 'blue', activebackground = 'blue', command = self.togglePlotPath)
			self.countPath = 0

			# Path files entry 
			self.label_path = tk.Label(self.topLevelWindow,text =  'Data Path')
			self.path = tk.Entry(self.topLevelWindow, width = 15, foreground='black',background='green')
			self.path.insert ( 0, '../data/' )
			PLANNER.PATH = self.path.get()
			# World's File entry 
			self.label_file = tk.Label(self.topLevelWindow,text =  'Environment File')
			self.file = tk.Entry(self.topLevelWindow, width = 15, foreground='black',background='green')
			self.file.insert ( 0, 'random_1' )
			File_Name = self.file.get()
			File_Name_robot = self.file.get()
			# Robot's File entry 
			#self.label_file_robot = tk.Label(self.topLevelWindow,text =  'Robot File (.raw) ')
			#self.file_robot = tk.Entry(self.topLevelWindow, width = 30, foreground='black',background='green')
			#self.file_robot.insert ( 0, 'random_5' )
			#File_Name_robot = self.file_robot.get()
			# Check button movement
			self.var_mov = IntVar()
		
			def command_mov():
				#print "Checkbutton variable is", self.var_mov.get()
				if self.var_mov.get() == 0:
					self.Movement.select()
					self.var_mov.set(1)
				else:
					self.Movement.deselect()
					self.var_mov.set(0)

			self.Movement = tk.Checkbutton(self.topLevelWindow, text="Show robot's single movements", variable= self.var_mov,command=command_mov)
			self.Movement.select()
			self.var_mov.set(1)
			#print 'flg_mov ',  self.var_mov.get()
			# Delay's plot robot entry 
			self.label_delay = tk.Label(self.topLevelWindow,text =  'Delay plotting')
			self.delay = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.delay.insert ( 0, '0.0' )
			PLANNER.delay = float(self.delay.get())
			
			# Check button sensor
			self.var_sensor = IntVar()

			def command_sensor():
				if self.var_sensor.get() == 0:
					self.sensor.select()
					self.var_sensor.set(1)
				else:
					self.sensor.deselect()
					self.var_sensor.set(0)

			self.sensor = tk.Checkbutton(self.topLevelWindow, text="show sensors", variable= self.var_sensor,command=command_sensor)
			self.sensor.select()
			self.var_sensor.set(1)


			# Check button add_noise
                	self.add_noise = IntVar()
                	def command_add_noise():
                        	if self.add_noise.get() == 0:
                                	self.noise.select()
                                	self.add_noise.set(1)
                        	else:
                                	self.noise.deselect()
                                	self.add_noise.set(0)

                	self.noise = tk.Checkbutton(self.topLevelWindow, text="Add noise", variable= self.add_noise,command=command_add_noise)
                	self.noise.deselect()
                	self.add_noise.set(1)


			# Number of sensors 
			self.label_num_sensors = tk.Label(self.topLevelWindow,text =  'Num. Sensors')
			self.num_sensors = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.num_sensors.insert ( 0, '50' )
			PLANNER.num_sensors = self.num_sensors.get()
			# Origen angle sensor 
			self.label_origen_angle = tk.Label(self.topLevelWindow,text =  'Origen angle sensor ')
			self.origen_angle = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.origen_angle.insert ( 0, '-1.5707' )
			origen_angle = self.origen_angle.get()
			# Range angle sensor 
			self.label_range_angle = tk.Label(self.topLevelWindow,text =  'Range angle sensor ')
			self.range_angle = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.range_angle.insert ( 0, '3.1415' )
			PLANNER.range_angle = self.range_angle.get()
			# Robot's magnitude advance  
			self.label_advance_robot = tk.Label(self.topLevelWindow,text =  "Robot's magnitude advance")
			self.advance_robot = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.advance_robot.insert(0,'0.15')
			advance_robot = self.advance_robot.get()
			# Robot's maximum angle  
			self.label_max_angle_robot = tk.Label(self.topLevelWindow,text =  "Robot's maximum turn angle")
			self.max_angle_robot = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.max_angle_robot.insert(0,'0.7854')
			max_angle_robot = self.max_angle_robot.get()
			# Robot's radio  
			self.label_radio_robot = tk.Label(self.topLevelWindow,text =  "Robot's radio")
			self.radio_robot = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.radio_robot.insert ( 0, '0.03' )
			PLANNER.radio_robot = float(self.radio_robot.get())
			# Robot's pose x  
			self.label_robot_posex = tk.Label(self.topLevelWindow,text =  "Robot's pose x")
			self.robot_posex = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.robot_posex.insert ( 0, '4.000' )
			PLANNER.pose_x = float(self.robot_posex.get())
			# Robot's pose y  
			self.label_robot_posey = tk.Label(self.topLevelWindow,text =  "Robot's pose y")
			self.robot_posey = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.robot_posey.insert ( 0, '5.000' )
			PLANNER.pose_y = self.robot_posey.get()
			# Robot's angle  
			self.label_robot_angle = tk.Label(self.topLevelWindow,text =  "Robot's angle")
			self.robot_angle = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.robot_angle.insert ( 0, '0.000' )
			PLANNER.pose_tetha = float(self.robot_angle.get())
			# Robot's command  
			#self.label_robot_command = tk.Label(self.topLevelWindow,text =  "Robot's command")
			self.label_left_button = tk.Label(self.topLevelWindow,text =  "Left mouse's button selects origen,")
			self.label_right_button = tk.Label(self.topLevelWindow,text = "right button selects destination")
			self.robot_command = tk.Entry(self.topLevelWindow, width = 30, foreground='black',background='green')
			self.robot_command.insert ( 0,"../motion_planner/GoTo_State_Machine")
			PLANNER.robot_command = self.robot_command.get()
			# Number of steps  
			self.label_number_steps = tk.Label(self.topLevelWindow,text =  "Number of Steps")
			self.number_steps = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.number_steps.insert ( 0, '10' )
			PLANNER.number_steps = self.number_steps.get()
			# Selection of behavior  
			self.label_selection = tk.Label(self.topLevelWindow,text =  "Behaviour Selection")
			self.selection = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.selection.insert ( 0, '1' )
			selection = self.selection.get()
			# Largest value sensor  
			self.label_largest = tk.Label(self.topLevelWindow,text =  "Largest value sensor")
			self.largest = tk.Entry(self.topLevelWindow, width = 8, foreground='black',background='green')
			self.largest.insert ( 0, '0.25' )
			largest = self.largest.get()
	
			# Add noise
	                #flg_noise = self.add_noise.get()
	

# _________________________________________G R I D S ______________________________________________________________________________


			#self.label_robot_command.grid({'row':0, 'column': 0})        
			self.label_left_button.grid({'row':7, 'column': 0})        
			self.label_right_button.grid({'row':8, 'column': 0})        
			#self.robot_command.grid({'row':0, 'column': 1})        
			#self.ExecuteButton.grid({'row':4, 'column': 0})
			self.label_path.grid({'row':1, 'column': 0})        
			self.path.grid({'row':1, 'column': 1})        
			self.label_file.grid({'row':2, 'column': 0})        
			self.file.grid({'row':2, 'column': 1})        
			#self.label_file_robot.grid({'row':3, 'column': 0})        
			#self.file_robot.grid({'row':3, 'column': 1})        
			#self.label_delay.grid({'row':0, 'column': 3})        
			#self.delay.grid({'row':0, 'column': 4})        
			self.MapButton.grid({'row':4, 'column': 0})
			self.RobotButton.grid({'row':6, 'column': 0})
			self.Movement.grid({'row':0, 'column': 2})
			self.sensor.grid({'row':1, 'column': 2})
			self.noise.grid({'row':2, 'column': 2})
			self.label_num_sensors.grid({'row':1, 'column': 3})        
			self.num_sensors.grid({'row':1, 'column': 4})        
			self.label_origen_angle.grid({'row':2, 'column': 3})        
			self.origen_angle.grid({'row':2, 'column': 4})        
			self.label_range_angle.grid({'row':3, 'column': 3})        
			self.range_angle.grid({'row':3, 'column': 4})        
			self.label_radio_robot.grid({'row':4, 'column': 3})        
			self.radio_robot.grid({'row':4, 'column': 4})        
			self.label_advance_robot.grid({'row':5, 'column': 3})        
			self.advance_robot.grid({'row':5, 'column': 4})        
			self.label_max_angle_robot.grid({'row':6, 'column': 3})        
			self.max_angle_robot.grid({'row':6, 'column': 4})        
			self.label_robot_posex.grid({'row':4, 'column': 1})        
			self.robot_posex.grid({'row':4, 'column': 2})        
			self.label_robot_posey.grid({'row':5, 'column': 1})        
			self.robot_posey.grid({'row':5, 'column': 2})        
			self.label_robot_angle.grid({'row':6, 'column': 1})        
			self.robot_angle.grid({'row':6, 'column': 2})        
			self.label_number_steps.grid({'row':7, 'column': 3})        
			self.number_steps.grid({'row':7, 'column': 4})        
			self.label_selection.grid({'row':7, 'column': 1})        
			self.selection.grid({'row':7, 'column': 2})        
			self.label_largest.grid({'row':8, 'column': 1})        
			self.largest.grid({'row':8, 'column': 2})        


#___________________________________________________________________________________________________ 



	def __init__(self):

                global C   	

		C = tk.Canvas(planner, bg="blue", height=DIM_CANVAS_X, width=DIM_CANVAS_Y)
		C.bind("<Button-1>", self.callback_mouse_1)
		C.bind("<Button-2>", self.callback_mouse_2)
		C.bind("<Button-3>", self.callback_mouse_3)
		C.bind("<Key>", self.callback_return)
		C.focus_set()
		C.pack()

		self.Start_GUI()
		self.read_file_map(1)

		rospy.init_node('mv_gui')
		s = rospy.Service('mv_gui_comm', MVServ, self.handle_mv_plot)
		s = rospy.Service('over_gui', OverSrv, self.handle_over)




	def sendInputs_client1(self):
		
		origin_x=PLANNER.mouse_1_x
		origin_y=PLANNER.mouse_1_y
		origin_angRob = float(self.robot_angle.get())
		PLANNER.destination_x=PLANNER.mouse_3_x
		PLANNER.destination_y=PLANNER.mouse_3_y
		dest_x=PLANNER.mouse_3_x
		dest_y=PLANNER.mouse_3_y
		sensorBool=str(self.sensor)
		num_sensorsInt = int(self.num_sensors.get())
		angle_sensor_orig = float(self.origen_angle.get())
		range_angleRob = float(self.range_angle.get())
		radiusRob = float(self.radio_robot.get())
		advance = float(self.advance_robot.get())
		max_angle = float(self.max_angle_robot.get())
		num_steps = int(self.number_steps.get())
		select = int(self.selection.get())
		largest_sensor = float(self.largest.get())
		pathNAme = self.path.get()
		fileNAme = self.file.get()
		flg_noise = self.add_noise.get()
	
	
		#print "Sending arguments to the Input node"
		rospy.wait_for_service('sendInputs')
		try:
			sendInputs=rospy.ServiceProxy('sendInputs',InputsSrv)			
			resp=sendInputs(origin_x,origin_y,origin_angRob,dest_x,dest_y,sensorBool,num_sensorsInt,angle_sensor_orig, 
					range_angleRob,radiusRob,advance,max_angle,num_steps,select,largest_sensor,pathNAme,fileNAme,flg_noise)
		except rospy.ServiceException, e:
			print "Service call failed %s"%e
		return resp.success

	def ovr_client(self):
		"""
		Function that checks if motion_planner has ended
		"""

		rospy.wait_for_service('over_gui')
		try:
			over_GUI=rospy.ServiceProxy('over_gui',OverSrv)			
			resp=over_GUI(1)
			#print 'Over_ gui ',resp.answer
			return resp.answer
		except rospy.ServiceException, e:
			print "Service call failed %s"%e
		


	def plot_polygon(self,num, data):

		XY= data
		#print "plot_polygon ",num
		for i in range(0, num):
			j=i*2 
			
			#print "data j ",j," x",data[j]," y ",data[j+1]
			X = ( DIM_CANVAS_X * data[j] ) / PLANNER.dim_x
			Y = DIM_CANVAS_Y - ( DIM_CANVAS_Y * data[j+1] ) / PLANNER.dim_y
			XY[j]=X;
			XY[j+1]=Y;
			#print "j ",j," X",XY[j]," Y ",XY[j+1]

		polygon = C.create_polygon(XY, outline='white', fill='red', width=1)
		return polygon


	def plot_line(self,x1,y1,x2,y2,color,flg):

		#print "x1 ",x1," y1 ",y1
		X1 = ( DIM_CANVAS_X * x1 ) / PLANNER.dim_x
		Y1 = DIM_CANVAS_Y - ( DIM_CANVAS_Y * y1 ) / PLANNER.dim_y
		#print "X1 ",X1," Y1 ",Y1

		#print "x2 ",x2," y2 ",y2
		X2 = ( DIM_CANVAS_X * x2 ) / PLANNER.dim_x
		Y2 = DIM_CANVAS_Y - ( DIM_CANVAS_Y * y2 ) / PLANNER.dim_y
		#print "X2 ",X2," Y2 ",Y2

		if flg == 1:
			line = C.create_line(X1,Y1,X2,Y2,fill=color, arrow="last")
		else:
			line = C.create_line(X1,Y1,X2,Y2,fill=color)
			id = C.create_rectangle(X2,Y2,X2+1,Y2+1, fill= "white", outline="white")


	def plot_oval(self,x,y):

		radio_robot= PLANNER.radio_robot

        	CNT=5.0
        	#print "plot robot pose_tetha ",pose_tetha
        	X = ( DIM_CANVAS_X * x ) / PLANNER.dim_x
        	Y = DIM_CANVAS_Y - ( DIM_CANVAS_Y * y ) / PLANNER.dim_y
        	ROBOT_radio = ( DIM_CANVAS_X * radio_robot ) / PLANNER.dim_x
        	X1 = X - ROBOT_radio
        	Y1 = Y - ROBOT_radio
        	X2 = X + ROBOT_radio
        	Y2 = Y + ROBOT_radio
        	#print "X1 ", X1, " Y1 ", Y1
        	#print "X2 ", X2, " Y2 ", Y2
        	oval = C.create_oval(X1,Y1,X2,Y2, outline="green",fill="yellow", width=1)


	def plot_robot(self):

		pose_tetha=PLANNER.pose_tetha
		radio_robot= PLANNER.radio_robot
		pose_x = PLANNER.pose_x
		pose_y = PLANNER.pose_y

		CNT=5.0
		#print "plot robot pose_tetha ",pose_tetha
		X = ( DIM_CANVAS_X * pose_x ) / PLANNER.dim_x
		Y = DIM_CANVAS_Y - ( DIM_CANVAS_Y * pose_y ) / PLANNER.dim_y
		ROBOT_radio = ( DIM_CANVAS_X * radio_robot ) / PLANNER.dim_x
		X1 = X - ROBOT_radio/2
		Y1 = Y - ROBOT_radio/2
		X2 = X + ROBOT_radio/2
		Y2 = Y + ROBOT_radio/2
		oval = C.create_oval(X1,Y1,X2,Y2, outline="red",fill="orange", width=1)


		x1 = pose_x
		y1 = pose_y
		angle_robot = pose_tetha
		tetha = angle_robot + PLANNER.start_angle
		x2 = x1 + (PLANNER.dim_x/25)*math.cos(angle_robot)
		y2 = y1 + (PLANNER.dim_y/25)*math.sin(angle_robot)
		self.plot_line(x1,y1,x2,y2,"white",1)

		PLANNER.mouse_3_x = pose_x
		PLANNER.mouse_3_y = pose_y



	def read_file_map(self,flg):

		id = C.create_rectangle(0, 0, DIM_CANVAS_X, DIM_CANVAS_Y, fill= "black")

		PLANNER.PATH = self.path.get()
		File_Name = self.file.get()

		#print 'Path ',PLANNER.PATH 
		#print 'File ',File_Name

		FILE = PLANNER.PATH + File_Name + '.wrl'

		file = open(FILE, 'r')

		for line in file:
			#print line,
			words = line.split()
			data = words
			#print len(words)
			#for i in range(0, len(words)):
			#print words[i]
			if len(words) > 1:
				if words[0] == ";(":
					j=0
				elif words[1] == "dimensions":
					PLANNER.dim_x = float(words[3])
					PLANNER.dim_y = float(words[4])
					#print 'dim_x ',PLANNER.dim_x, 'dim_y ',PLANNER.dim_y


				elif words[1] == "polygon":
					j=0
					data = [0] * (len(words) - 5)
					for i in range(4, len(words) -1):
						#print words[i]
						data[j] = float(words[i])
						j=j+1

					j=j+1
					num = j / 2
					if flg == 1:
						self.polygons.append(self.plot_polygon(num,data))
						self.num_pol = self.num_pol + 1
					else:
						self.plot_polygon(num,data)

	def handle_info(req):
		#print req.order
		st=req.order
		return GUISrvResponse(1)

	def get_info():
		rospy.init_node('get_info')
		s = rospy.Service('get_info', GUISrv, handle_info)
		#print "Ready to det some intel."
		print s,type(s)
		#rospy.spin()


      	def read_plot_line(self, line, num_steps):
		global num_steps_ros

		#print "read_plot_line ",line

		flg_mov = self.var_mov.get()
		flg_sensor = self.var_sensor.get()

                words = line.split()
                data = words

                #print len(words)
                #for i in range(0, len(words)): print words[i]

                if len(words) > 1:
                        if words[0] == ";(":
                                j=0
                        elif words[1] == "polygon":
                                j=0
                                data = [0] * (len(words) - 5)
                                for i in range(4, len(words) -1):
                                        #print words[i]
                                        data[j] = float(words[i])
                                        j=j+1

                                j=j+1
                                num = j / 2
                                if flg == 1:
                                        PLANNER.polygons.append(self.plot_polygon(num,data))
                                        PLANNER.num_pol = PLANNER.num_pol + 1
                                else:
                                        self.plot_polygon(num,data)


                        elif words[1] == "dimensions":
                                PLANNER.dim_x = float(words[3])
                                PLANNER.dim_y = float(words[4])
                                #print 'dim_x ',PLANNER.dim_x, 'dim_y ',PLANNER.dim_y

                        elif words[1] == "radio_robot":
                                PLANNER.radio_robot = float(words[2])
                                #print 'radio robot ',PLANNER.radio_robot

                        elif words[1] == "delete":
                                for i in range(0,num_pol):
                                        C.delete(PLANNER.polygons[i])

		
			elif words[1] == "destination":
                        	x = float(words[2])
                        	y = float(words[3])
                        	self.plot_oval(x,y)



                        elif words[1] == "robot":
				
                                PLANNER.pose_x = float(words[3])
                                PLANNER.pose_y = float(words[4])
                                PLANNER.pose_tetha = float(words[5])

				#print "plot robot x ",str(PLANNER.pose_x)," y ",str(PLANNER.pose_y)," tetha ",PLANNER.pose_tetha
                                angle_robot = PLANNER.pose_tetha
                                str_angle = ("%3.4f" % angle_robot).strip()
                                self.robot_angle.delete(0, END)
                                self.robot_angle.insert(0,str_angle)
                                self.robot_posex.delete(0, END)
                                self.robot_posex.insert (0, words[3] )
                                self.robot_posey.delete(0, END)
                                self.robot_posey.insert (0, words[4] )

				str_num_steps = ("%4d" % num_steps_ros).strip()
                                self.number_steps.delete(0, END)
                                self.number_steps.insert(0,str_num_steps)

                                num_steps_ros = num_steps_ros + 1
				
				if flg_mov == 1:
                                                id = C.create_rectangle(0, 0, DIM_CANVAS_X, DIM_CANVAS_Y, fill= "black")
                                                self.read_file_map(0)


                                self.plot_robot()
				x = PLANNER.destination_x
                		y = PLANNER.destination_y 
				self.plot_oval(x,y)

                                if self.var_mov.get() == 0:
                                        C.update_idletasks()
                                else:
                                        if flg_sensor == 0:
                                                C.update_idletasks()

                                C.update_idletasks()


                        elif words[1] == "sensor":

				#print "word[2] ",words[2]
				if flg_sensor == 1:


					x1 = float(words[3])
					y1 = float(words[4])
					angle_robot = float(words[5])

					PLANNER.pose_tetha = angle_robot
		                        PLANNER.pose_x=x1
                        		PLANNER.pose_y=y1
                                        self.plot_robot()
                                	C.update_idletasks()


                                        #num = int(words[3])
                                        num = int(words[6])
		
                                        #PLANNER.range_angle = float(words[4])
                                        PLANNER.range_angle = float(words[7])
                                        #PLANNER.start_angle = float(words[5])
                                        PLANNER.start_angle = float(words[8])
                                        if num == 1:
                                                delta_angle = PLANNER.range_angle
                                        else:
                                                delta_angle = PLANNER.range_angle / (num - 1)
                                        #print "num ", str(num), "Range Measurments ", str(PLANNER.range_angle)
                                        #print "Start angle ", str(PLANNER.start_angle), " Delta Angle ", str(delta_angle)

                                        #x1 = PLANNER.pose_x
                                        #y1 = PLANNER.pose_y
                                	#angle_robot = PLANNER.pose_tetha

                                        tetha = angle_robot + PLANNER.start_angle
                                        x2 = x1 + (PLANNER.dim_x/10)*math.cos(angle_robot)
                                        y2 = y1 + (PLANNER.dim_y/10)*math.sin(angle_robot)
                                        self.plot_line(x1,y1,x2,y2,"red",1)
                                        #print "sensor angle_robot ",angle_robot
                                        #print "Origen Tetha ", tetha
                                        #print "sen ", tetha, " = ",math.sin(tetha)

                                        #data = [0] * (len(words) - 5)
                                        data = [0] * (len(words) - 8)
                                        j=0
                                        #for i in range(6, len(words) -1):
                                        for i in range(9, len(words) -1):
                                                #print words[i]
                                                #print "Tetha ", j," ",tetha
                                                data[j] = float(words[i])
                                                x2 = x1 + data[j]*math.cos(tetha)
                                                y2 = y1 + data[j]*math.sin(tetha)
                                                self.plot_line(x1,y1,x2,y2,"#FFD1AA",0)
                                                j=j+1
                                                tetha = tetha + delta_angle
                                                #print "sen ", tetha, " = ",math.sin(tetha)
                                		C.update_idletasks()

					x = PLANNER.destination_x
                			y = PLANNER.destination_y 
					self.plot_oval(x,y)
					#print "oval x ",str(x)," y ",str(y)

                                        C.update_idletasks()

		C.update_idletasks()





	def read_file(self,flg):


		PLANNER.PATH = self.path.get()
		#File_Name_robot = self.file_robot.get()
		File_Name_robot = self.file.get()
		FILE = PLANNER.PATH + File_Name_robot + '.raw'
		file = open(FILE, 'r')

		C.update_idletasks() # it updates the ide data
		delay = float(self.delay.get())
		PLANNER.delay = delay
		flg_mov = self.var_mov.get()
		flg_sensor = self.var_sensor.get()
		number_steps = self.number_steps.get()
		num_steps = 1

		flg_mov = self.var_mov.get()

		for line in file:
			#print line,
			words = line.split()
			data = words
			#print len(words)
			#for i in range(0, len(words)):
			#print words[i]
			if len(words) > 1:
				if words[0] == ";(":
					j=0
				elif words[1] == "polygon":
					j=0
					data = [0] * (len(words) - 5)
					for i in range(4, len(words) -1):
						#print words[i]
						data[j] = float(words[i])
						j=j+1 
						
					j=j+1 
					num = j / 2
					if flg == 1:
						PLANNER.polygons.append(self.plot_polygon(num,data))
						PLANNER.num_pol = PLANNER.num_pol + 1
					else:
						self.plot_polygon(num,data)


				elif words[1] == "dimensions":
					PLANNER.dim_x = float(words[3])
					PLANNER.dim_y = float(words[4])
					#print 'dim_x ',PLANNER.dim_x, 'dim_y ',PLANNER.dim_y

				elif words[1] == "radio_robot":
					PLANNER.radio_robot = float(words[2])
					#print 'radio robot ',PLANNER.radio_robot

				elif words[1] == "delete":
					for i in range(0,PLANNER.num_pol):
						C.delete(PLANNER.polygons[i])


				elif words[1] == "destination":
	                                x = float(words[2])
                                	y = float(words[3])
                                	self.plot_oval(x,y)



				elif words[1] == "robot":
					PLANNER.pose_x = float(words[3])
					PLANNER.pose_y = float(words[4])
					PLANNER.pose_tetha = float(words[5])

					angle_robot = PLANNER.pose_tetha
					str_angle = ("%3.4f" % angle_robot).strip()
					self.robot_angle.delete(0, END)
					self.robot_angle.insert(0,str_angle)
					self.robot_posex.delete(0, END)
					self.robot_posex.insert (0, words[3] )
					self.robot_posey.delete(0, END)
					self.robot_posey.insert (0, words[4] )
					str_num_steps = ("%4d" % num_steps).strip()
					self.number_steps.delete(0, END)
					self.number_steps.insert(0,str_num_steps)
					num_steps = num_steps + 1

					if flg_mov == 1:
						id = C.create_rectangle(0, 0, DIM_CANVAS_X, DIM_CANVAS_Y, fill= "black")
						self.read_file_map(0)


					self.plot_robot()

					x = PLANNER.destination_x
                                        y = PLANNER.destination_y
                                        self.plot_oval(x,y)

					if self.var_mov.get() == 0:
						C.update_idletasks()
					else:
						if flg_sensor == 0:
							C.update_idletasks()



					if flg_mov == 1:
						time.sleep(delay/2.0) # delays seconds

				elif words[1] == "sensor":
					if flg_sensor == 1:
						if flg_mov == 1:
							id = C.create_rectangle(0, 0, DIM_CANVAS_X, DIM_CANVAS_Y, fill= "black")
							self.read_file_map(0)

						self.plot_robot()

						num = int(words[3])

						PLANNER.range_angle = float(words[4])
						PLANNER.start_angle = float(words[5])
						if num == 1:
							delta_angle = PLANNER.range_angle 
						else:
							delta_angle = PLANNER.range_angle / (num - 1)
						#print "num ", num, "Range Measurments ", PLANNER.range_angle
						#print "Start angle ", start_angle, " Delta Angle ", PLANNER.delta_angle

						x1 = PLANNER.pose_x 
						y1 = PLANNER.pose_y
						angle_robot = PLANNER.pose_tetha

						tetha = angle_robot + PLANNER.start_angle
						x2 = x1 + (PLANNER.dim_x/10)*math.cos(angle_robot)
						y2 = y1 + (PLANNER.dim_y/10)*math.sin(angle_robot)
						#self.plot_line(x1,y1,x2,y2,"red",1)
						#print "sensor pose tetha ",pose_tetha
						#print "sensor angle_robot ",angle_robot
						#print "Origen Tetha ", tetha
						#print "sen ", tetha, " = ",math.sin(tetha)

						data = [0] * (len(words) - 5)
						j=0
						for i in range(6, len(words) -1):
							#print words[i]
							#print "Tetha ", j," ",tetha
							data[j] = float(words[i])
							x2 = x1 + data[j]*math.cos(tetha)
							y2 = y1 + data[j]*math.sin(tetha)
							self.plot_line(x1,y1,x2,y2,"cyan",0)
							j=j+1
							tetha = tetha + delta_angle
							#print "sen ", tetha, " = ",math.sin(tetha)


						x = PLANNER.destination_x
                                                y = PLANNER.destination_y
                                                self.plot_oval(x,y)

						C.update_idletasks()
						

		file.close()
		self.number_steps.delete(0, END)
		self.number_steps.insert(0,PLANNER.number_steps)


#------------------------------------------------------------------------------------------

# Functions that handle the buttons

	def togglePlotRobot(self):
 
 
		self.RobotButton['bg'] = 'red'
		self.RobotButton['activebackground'] = 'red'


		# uniform gives you a floating-point value
		#pose_x = uniform(0, dim_x)
		#pose_y = uniform(0, dim_y)
		#pose_tetha = uniform(0, 2*3.1416)
		#self.plot_robot()

		C.update_idletasks()

		PLANNER.PATH = self.path.get()
		#print 'Plot Robot PATH ',PLANNER.PATH

		File_Name = self.file.get()
		#print 'Plot Robot File_Name ',File_Name

		#File_Name_robot = self.file_robot.get()
		File_Name_robot = self.file.get()
		#print 'Plot Robot File_Name_robot ',File_Name_robot

		self.read_file_map(0)
		self.read_file(1)

		self.RobotButton['bg'] = 'green'
		self.RobotButton['activebackground'] = 'green'



	def togglePlotMap(self):

		self.MapButton['bg'] = 'red'
		self.MapButton['activebackground'] = 'red'

		C.update_idletasks()

		PLANNER.PATH = self.path.get()
		#print 'Plot Map PATH ',PLANNER.PATH

		File_Name = self.file.get()
		#print 'Plot Map File_Name ',File_Name

		flg_mov = self.var_mov.get()
		#print 'Plot Robot flg_mov',flg_mov

		flg_sensor = self.var_sensor.get()
		#print 'Plot Robot flg_sensor ',flg_sensor

		self.read_file_map(0)

		self.MapButton['bg'] = 'green'
		self.MapButton['activebackground'] = 'green'

		str_angle = "0.00000"
		self.robot_angle.delete(0, END)
		self.robot_angle.insert(0,str_angle)
		self.number_steps.delete(0, END)
                self.number_steps.insert(0,PLANNER.number_steps)




	def startPlotExecute(self):
		global flg_execute
		global flag_thread


		flag_thread = 0
		self.read_file_map(0)
		self.sendInputs_client1()
		flg_execute = 1




	def togglePlotExecute(self):

		C.update_idletasks()

		self.ExecuteButton['bg'] = 'red'
		self.ExecuteButton['activebackground'] = 'red'
		C.update_idletasks()

		flg_mov = self.var_mov.get()
		flg_sensor = self.var_sensor.get()
		PLANNER.delay = float(self.delay.get())
		self.read_file_map(0)
		self.read_file(1)


		self.ExecuteButton['bg'] = 'blue'
		self.ExecuteButton['activebackground'] = 'blue'

		PLANNER.mouse_1_x = PLANNER.pose_x
		PLANNER.mouse_1_y = PLANNER.pose_y
		

	def togglePlotPath(self):

		if self.countPath == 1:
			self.PathButton['bg'] = 'blue'
			self.PathButton['activebackground'] = 'blue'
		else:
			self.PathButton['bg'] = 'red'
			self.PathButton['activebackground'] = 'red'
		self.countPath = 0

		#print 'PlotPath num_pol ' + str(PLANNER.num_pol)

		for i in range(0,PLANNER.num_pol):
			C.delete(PLANNER.polygons[i])



#_______________________________________________________________________________________



# Class definition to plot the robot in the GUI using QUEUES
class App:

    global gui_planner


    def __init__(self, queue, width=400, height=300):

        self.width, self.height = width, height
        self.canvas = tk.Canvas(width=width, height=height, bg='black')
        self.canvas.pack(fill='none', expand=False)
        self.queue = queue
        self.canvas.after(50, self.check_queue)



# Queue to plot partial movements of the robot
    def check_queue(self):
	global flg_finish
	global flg_execute
	global num_steps_ros
	global s_r
	global index
	global prev_index


        try:
            x = self.queue.get(block=False)
        except Queue.Empty:
            pass
        else:
	    #print "flg_finish ",flg_finish," s_ros ",s_ros
	    if flg_finish == 0:
		j=index
		for i in range(prev_index, j+1):
			#print "plotting s_r[",str(i),"] = ",s_r[i]
            		gui_planner.read_plot_line(s_r[i], 1)
		if index != 0:
			prev_index = j
		else:
			prev_index = 1
	    else:
		flg_execute = 1
	    	gui_planner.togglePlotExecute()
		num_steps_ros = 1
		gui_planner.number_steps.delete(0, END)
                gui_planner.number_steps.insert(0,PLANNER.number_steps)
		flg_finish = 0
		index = 0
		prev_index = 1


        self.canvas.after(50, self.check_queue)
	self.canvas.update_idletasks()



# Thread that puts a queue to plot partial movements of the robot
def queue_create(queue, running):
    global flag_thread

    count = 0

    while running:

        if flag_thread == 1:
            count += 1
            flag_thread = 0
            #print "Queing ROS command",str(count),":", s_ros
            queue.put(1)

        time.sleep(0) # Effectively yield this thread.



# It plots teh complete robot's path 
def ThreadPlotExecute(queue, running):
		global flg_execute
		global flg_finish
    		global event_mouse_3
		global flag_over


    		while running:
                        while flg_execute == 0:
                                time.sleep(0)
			#print "flg_execute ",flg_execute

                        # Wait until motion planner has finished
                        flag_over = 0
                        while flag_over == 0:
                                #over = gui_planner.ovr_client()
				time.sleep(1)
                        os.system('clear')

                        #print "=================================================="
                        #print "|            FINISH COMMAND EXECUTION            |"
                        #print "=================================================="

			flag_over = 0
			flg_finish = 1
            		queue.put(1)
	




#------------------------------------------------
#  MAIN						#
#------------------------------------------------

if __name__ == '__main__':

	running = [True]
	queue = Queue.Queue()
	app = App(queue)
	thread = threading.Thread(target=queue_create, args=(queue, running))
	thread.start()


	planner = tk.Tk()
	planner.wm_title('PLANNER_ROS')
	planner.bind("<Configure>", callback_resize)
	print "GUI node started"
	thread_plot_execute = threading.Thread(target=ThreadPlotExecute, args=(queue, running))
	thread_plot_execute.start()


	gui_planner = PLANNER()
	tk.mainloop()


