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
       



class PLANNER(object):
   

	global_angle=0;
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
			id = C.create_rectangle(event.x, event.y, event.x+1, event.y+1, fill= "yellow")
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
	def handle_over_hapi(self,req):
                        global flag_over

                        over_ros=req.over_flg
                        #print "new over >> over_ros = %d"%(over_ros)
                        flag_over = 1
                        time.sleep(0)
                        #return MVServResponse("_")
                        return OverSrvResponse(1)


	def Start_GUIT(self):


			self.topLevelWindow = tk.Tk()
			self.topLevelWindow.wm_title('ROS_MOVEMENTS')

#________________________________________ BUTTONS''DEFINITIONS ______________________________________________________________________________________________________________________________
			self.label_title = tk.Label(self.topLevelWindow,width = 20,height=2,text =  "Movement and direction")
			# Plot Robot button
			photo = PhotoImage(file="../GUI/arrow.png")
			self.Button0 =tk.Button(self.topLevelWindow, width = 2, height=1, text = ">", bg = 'green', activebackground = 'green', command = self.turn270)
			self.countRobot = 0

			# Plot Robot button
			self.Button45 = tk.Button(self.topLevelWindow, width = 2,height=1, text = ">", bg = 'green', activebackground = 'green', command = self.turn315)
			self.countRobot = 0

			# Plot Robot button
			self.Button90 = tk.Button(self.topLevelWindow, width = 2,height=1, text = "/\\", bg = 'green', activebackground = 'green', command = self.turn0)
			self.countRobot = 0

			# Plot Robot button
			self.Button135 = tk.Button(self.topLevelWindow, width = 2,height=1, text = "<", bg = 'green', activebackground = 'green', command = self.turn45)
			self.countRobot = 0

			# Plot Robot button
			self.Button180 = tk.Button(self.topLevelWindow, width = 2,height=1, text = "< ", bg = 'green', activebackground = 'green', command = self.turn90)
			self.countRobot = 0

			# Plot Robot button
			self.Button225 = tk.Button(self.topLevelWindow, width = 2,height=1, text = "<", bg = 'green', activebackground = 'green', command = self.turn135)
			self.countRobot = 0

			# Plot Robot button
			self.Button270 = tk.Button(self.topLevelWindow, width = 2,height=1, text = "v ", bg = 'green', activebackground = 'green', command = self.turn180)
			self.countRobot = 0

			# Plot Robot button
			self.Button315 = tk.Button(self.topLevelWindow, width = 2,height=1, text = ">", bg = 'green', activebackground = 'green', command = self.turn225)
			self.countRobot = 0

			self.label_empty0 = tk.Label(self.topLevelWindow,width = 2,height=1,text =  " ")
			self.label_empty1 = tk.Label(self.topLevelWindow,width = 2,height=1,text =  " ")
			self.label_empty2 = tk.Label(self.topLevelWindow,width = 2,height=1,text =  " ")
			self.label_empty3 = tk.Label(self.topLevelWindow,width = 2,height=1,text =  " ")

			self.label_empty4 = tk.Label(self.topLevelWindow,width = 2,height=1,text =  " ")
			self.label_title_angle_distance = tk.Label(self.topLevelWindow,width = 20,height=2,text =  "Angle and distance")

			self.label_angle = tk.Label(self.topLevelWindow,text =  'Angle')
			self.label_distance = tk.Label(self.topLevelWindow,text =  'Distance')
			
			self.angle_value = tk.Entry(self.topLevelWindow, width = 6, foreground='black',background='green')
			self.angle_value.insert ( 0, '1.5707' )

			self.distance_value = tk.Entry(self.topLevelWindow, width = 6, foreground='black',background='green')
			self.distance_value.insert ( 0, '0.04')

			self.Button_send_comand = tk.Button(self.topLevelWindow, width = 10,height=1, text = "Send comand", bg = 'green', activebackground = 'green', command = self.send_comand)
			self.countRobot = 0
			



			
			# Add noise
	                #flg_noise = self.add_noise.get()
	

# _________________________________________G R I D S ______________________________________________________________________________

			self.label_empty4.grid({ 'row':8, 'column': 1},columnspan=10);
			self.label_title_angle_distance.grid({ 'row':9, 'column': 2},columnspan=10);

			self.label_angle.grid({ 'row':10, 'column': 0},columnspan=2);
			self.angle_value.grid({ 'row':10, 'column': 2},columnspan=2);
			self.label_distance.grid({ 'row':10, 'column': 4},columnspan=2);
			self.distance_value.grid({ 'row':10, 'column': 6},columnspan=2);
			
			self.label_title.grid({'row':0, 'column': 1}, columnspan=10)  
			self.Button0.grid({ 'row':4, 'column': 7})
			self.Button45.grid({'row':2, 'column': 6})
			self.Button90.grid({'row':1, 'column': 4})
			self.Button135.grid({'row':2, 'column': 2})
			self.Button180.grid({'row':4, 'column': 1})
			self.Button225.grid({'row':6, 'column': 2})
			self.Button270.grid({'row':7, 'column': 4})
			self.Button315.grid({'row':6, 'column': 6})

			self.label_empty0.grid({'row':3, 'column': 3})
			self.label_empty1.grid({'row':3, 'column': 5})
			self.label_empty2.grid({'row':5, 'column': 3})
			self.label_empty3.grid({'row':5, 'column': 5})
			self.Button_send_comand.grid({'row':11, 'column': 1}, columnspan=10)
			
###############################################################333333333
#___________________________________________________________________________________________________ 



	def __init__(self):

  
	
		self.Start_GUIT()

		rospy.init_node('mv_gui_hapi')
		s = rospy.Service('over_gui2', OverSrv, self.handle_over_hapi)




	def sendCoord(self):
		
		param=self.param
		coord_x=.5
		coord_y=.5
		coord_ang=self.global_angle
		print 'holaholaa'

		rospy.wait_for_service('receptor')
		try:
			sendInputs=rospy.ServiceProxy('receptor',MVServ)			

			resp=sendInputs(param,coord_x,coord_y,coord_ang)
		except rospy.ServiceException, e:
			print "Service call failed %s"%e


		return resp.answer

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
		


	




#------------------------------------------------------------------------------------------

# Functions that handle the buttons
	def send_comand(self):
		self.param="mv "+self.distance_value.get()+" "+self.angle_value.get()            
		self.sendCoord();
	def turn0(self):
		self.param="0"
		self.global_angle=0            
		self.sendCoord();
	def turn45(self):
		self.param="0"
		self.global_angle=.7853              
		self.sendCoord();
	def turn90(self):
		self.param="0"      
		self.global_angle=.7853*2        
		self.sendCoord();
	def turn135(self):   
		self.param="0" 
		self.global_angle=.7853*3        
		self.sendCoord();
	def turn180(self):      
		self.param="0"
		self.global_angle=.7853*4      
		self.sendCoord();

	def turn225(self):
		self.param="0"           
		self.global_angle=.7853*5 
		self.sendCoord();
	def turn270(self):
		self.param="0"           
		self.global_angle=.7853*6 
		self.sendCoord();
	def turn315(self):
		self.param="0"           
		self.global_angle=.7853*7 
		self.sendCoord();

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

		self.MapButton['bg'] = 'yellow'
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




#------------------------------------------------
#  MAIN						#
#------------------------------------------------

if __name__ == '__main__':

	running = [True]
	gui_planner = PLANNER()
	tk.mainloop()


