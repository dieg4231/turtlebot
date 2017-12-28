;;;===================================================
;;;         Acomodar dos pilas de cubos
;;;
;;;       +------+              +------+ 
;;;      /      /|             /      /|
;;;     +------+ |            +------+ |
;;;     |  A   | +            |   D  | +
;;;     |      |/             |      |/
;;;     +------+              +------+      
;;;       +------+              +------+ 
;;;      /      /|             /      /|
;;;     +------+ |            +------+ |
;;;     |  B   | +            |   E  | +
;;;     |      |/             |      |/
;;;     +------+              +------+      
;;;       +------+              +------+ 
;;;      /      /|             /      /|
;;;     +------+ |            +------+ |
;;;     |  C   | +            |   F  | +
;;;     |      |/             |      |/
;;;     +------+              +------+       
;;;===================================================

;;****************
;;* DEFTEMPLATES *
;;****************

(deftemplate stack
   (slot name     (type SYMBOL) 
                  (allowed-values s1 s2 s3 s4 s5 s6 v) 
                  (default v))
   (slot ab       (type SYMBOL) 
                  (allowed-values a b c d e f g v) 
                  (default v))
   
   (slot en       (type SYMBOL) 
                  (allowed-values a b c d e f g v) 
                  (default v))
   
   (slot ar       (type SYMBOL) 
                  (allowed-values a b c d e f g v) 
                  (default v))
   (slot goal    (type SYMBOL) 
                  (allowed-values t1 t2 v) 
                  (default v))
)

(deftemplate goal (slot move) (slot on-top-of) )



;;****************
;;*   DEFFACTS   *
;;****************

(deffacts inicia
   (stack (name s1) (ab f) (en c) (ar e ) )
   (stack (name s2) (ab b) (en a) (ar d ) )
   (stack (name s3) )
   (stack (name s4) )
   (stack (name s5) )   
   (stack (name s6)  )
   (stack (goal t1) (name s2 ) (ab a) (en b) (ar c) )
   (stack (goal t2) (name s3 ) (ab d) (en e) (ar f) )
   (goal (move v) (on-top-of v))
   
)


;;;***************
;;;*    REGLAS   *
;;;***************


(defrule finish ""
    ?g1 <- (stack (goal t1) (name ?name1 ) (ab ?ab1 ) (en ?en1 ) (ar ?ar1 ) )
    ?g2 <- (stack (goal t2) (name ?name2 ) (ab ?ab2 ) (en ?en2 ) (ar ?ar2 ) )
    ?f1 <- (stack (goal v) (name ?name1 ) (ab ?ab1 ) (en ?en1 ) (ar ?ar1 ) )
    ?f2 <- (stack (goal v) (name ?name2 ) (ab ?ab2 ) (en ?en2 ) (ar ?ar2 ) )
   =>
    (printout t "Tarea terminada." crlf)
    (exit)
)

(defrule  si-la-base-no-es ""
    ?g1 <- (stack (goal t1|t2) (name ?name1 ) (ab ?ab1 )   (en ?en1 ) (ar ?ar1 )  )
    ?f1 <- (stack (goal v) (name ?name1 ) (ab ?abf1&~v&~?ab1 )  (en ?enf1 ) (ar ?arf1 ) )
   =>
     (printout t "" ?name1 crlf )
     (printout t "Poner "  ?arf1  " en el suelo" crlf) (assert  ( on_floor ?arf1 ?name1 )  )  
     (printout t "Poner "  ?enf1  " en el suelo" crlf) (assert  ( on_floor ?enf1 ?name1 )  )
    (printout t "Poner "  ?abf1 " en el suelo" crlf)
    (assert  ( on_floor ?abf1 ?name1 )  )
    
    (modify ?f1 (ab  v) (en  v) (ar   v))   
)

(defrule  si-los-de-enmedio-no-son ""

    ?g1 <- (stack (goal t1|t2) (name ?name1 ) (ab ?ab1 )   (en ?en1 ) (ar ?ar1 )  )
    ?f1 <- (stack (goal v) (name ?name1 ) (ab ?ab1 )  (en ?enf1&~v&~?en1 ) (ar ?arf1 ) )
   =>
    (printout t "" ?name1 crlf )
    (printout t "Poner "  ?arf1  " en el suelo" crlf) (assert  ( on_floor ?arf1 ?name1 )  )   
    (printout t "Poner "  ?enf1  " en el suelo" crlf) (assert  ( on_floor ?enf1 ?name1 )  )
    (modify ?f1  (en  v) (ar   v))   
)

(defrule  si-los-de-arriba-no-son ""
    ?g1 <- (stack (goal t1|t2) (name ?name1 ) (ab ?ab1 )   (en ?en1 ) (ar ?ar1 )  )
    ?f1 <- (stack (goal v) (name ?name1 ) (ab ?ab1 )  (en ?en1) (ar ?arf1&~v&~?ar1  ) )
   =>
    (printout t "" ?name1 crlf )
    (printout t "Poner "  ?arf1  " en el suelo" crlf) (assert  ( on_floor ?arf1 ?name1 )  )
    (modify ?f1 (ar   v))   
)


(defrule  pone_los_de_abajo ""

    ?g<- (goal (move ?x&v) (on-top-of ?pila&v ) )
    ?g1 <- (stack (goal t1|t2) (name ?name1 ) (ab ?ab1 )   (en ?en1 ) (ar ?ar1 )  )
    ?f1 <- (stack (goal v) (name ?name1 ) (ab ?abf1&v  )  (en ?enf1&v ) (ar ?arf1&v ) )
   =>
      (modify ?g  (move ?ab1 ) (on-top-of ?name1) )

)

(defrule  pone_los_de_enmedio ""

    ?g<- (goal (move ?x&v) (on-top-of ?pila&v ) )
    ?g1 <- (stack (goal t1|t2) (name ?name1 ) (ab ?ab1 )   (en ?en1 ) (ar ?ar1 )  )
    ?f1 <- (stack (goal v) (name ?name1 ) (ab ?ab1  )  (en ?enf1&v ) (ar ?arf1&v ) )
   =>
      (modify ?g  (move ?en1 ) (on-top-of ?name1) )
)

(defrule  pone_los_de_ariba ""

    ?g<- (goal (move ?x&v) (on-top-of ?pila&v ) )
    ?g1 <- (stack (goal t1|t2) (name ?name1 ) (ab ?ab1 )   (en ?en1 ) (ar ?ar1 )  )
    ?f1 <- (stack (goal v) (name ?name1 ) (ab ?ab1  )  (en ?en1 ) (ar ?arf1&v ) )
   =>
      (modify ?g  (move ?ar1 ) (on-top-of ?name1) )
)

(defrule  agarrar_suelo ""
      ?g<- (goal (move ?x&~v) (on-top-of ?pila&~v ) )
      ?f1 <- (stack (goal v) (name ?pila ) (ab ?abf1 ) (en ?enf1 ) (ar ?arf1 )  )
      ?echo <-(on_floor ?x ?suelo )
   =>

  (printout t "" ?suelo crlf)  
  (printout t "Tomar el cubo " ?x  crlf)
  (retract ?echo )
  (printout t "" ?pila  crlf)
  (printout t "Poner el cubo sobre la pila"crlf)
   
  (if (eq ?abf1 v) then (modify ?f1 (ab ?x)) else
  (if (eq ?enf1 v) then (modify ?f1 (en ?x)) else
  (if (eq ?arf1 v) then (modify ?f1 (ar ?x)) 
  )
  )  
  ) 

  (modify ?g (move v) (on-top-of v))
)

(defrule  agarrar_arriba_de_pila ""
    
    ?g<- (goal (move ?x&~v) (on-top-of ?pila&~v ) )
    ?f1 <- (stack (goal v) (name ?pila ) (ab ?abf1 ) (en ?enf1 ) (ar ?arf1 )  )
    ?f2 <- (stack (goal v) (name ?name2 ) (ab ?abf2&~v )  (en ?enf2&~v ) (ar ?x ) )
   =>
  (printout t "" ?name2 crlf)
  (printout t "Tomar el cubo " ?x  crlf)
  (printout t "" ?pila  crlf)
  (printout t "Poner el cubo sobre la pila "crlf)
  (modify ?f2 (ar v))
   
  (if (eq ?abf1 v) then (modify ?f1 (ab ?x)) else
  (if (eq ?enf1 v) then (modify ?f1 (en ?x)) else
  (if (eq ?arf1 v) then (modify ?f1 (ar ?x)) 
  )
  )  
  ) 

  (modify ?g (move v) (on-top-of v)) 
)

(defrule  agarrar_de_enmedio ""
    ?g<- (goal (move ?x&~v) (on-top-of ?pila&~v ) )
    ?f1 <- (stack (goal v) (name ?pila ) (ab ?abf1 ) (en ?enf1 ) (ar ?arf1 )  )
    ?f2 <- (stack (goal v) (name ?name2 ) (ab ?abf2 )  (en ?x ) (ar ?arf2&~v ) )
   =>
  
  (printout t "" ?name2 crlf)  
  

   
  (printout t "Tomar el cubo " ?arf2 crlf)
  (printout t "Ponerlo en el suelo " crlf)
  (assert (on_floor ?arf2 ?name2 ))   
  (printout t "Tomar el cubo  " ?x  crlf) 
  (modify ?f2  (ab ?abf2)  (en v) (ar v )) 
  (printout t "" ?pila  crlf)
  (printout t "Poner el cubo sobre la pila "crlf)
   
  (if (eq ?abf1 v) then (modify ?f1 (ab ?x)) else
  (if (eq ?enf1 v) then (modify ?f1 (en ?x)) else
  (if (eq ?arf1 v) then (modify ?f1 (ar ?x)) 
  )
  )  
  ) 

  (modify ?g (move v) (on-top-of v))   
)

(defrule  agarrar_de_enmedio_sin_nada_arriba ""
    
    ?g<- (goal (move ?x&~v) (on-top-of ?pila&~v ) )
    ?f1 <- (stack (goal v) (name ?pila ) (ab ?abf1 ) (en ?enf1 ) (ar ?arf1 )  )
    ?f2 <- (stack (goal v) (name ?name2 ) (ab ?abf2 )  (en ?x ) (ar  v ) )
   =>
  (printout t "" ?name2 crlf)  

  (printout t "Tomar el cubo  " ?x  crlf) 
  (modify ?f2  (ab ?abf2)  (en v) )

  (printout t "" ?pila  crlf)
  (printout t "Poner el cubo sobre la pila "crlf)
   
  (if (eq ?abf1 v) then (modify ?f1 (ab ?x)) else
  (if (eq ?enf1 v) then (modify ?f1 (en ?x)) else
  (if (eq ?arf1 v) then (modify ?f1 (ar ?x)) 
  )
  )  
  ) 

  (modify ?g (move v) (on-top-of v))   
)




(defrule  agarrar_de_abajo ""
    ?g<- (goal (move ?x&~v) (on-top-of ?pila&~v ) )
    ?f1 <- (stack (goal v) (name ?pila ) (ab ?abf1 ) (en ?enf1 ) (ar ?arf1 )  )
    ?f2 <- (stack (goal v) (name ?name2 ) (ab ?x )  (en ?enf2&~v ) (ar ?arf2&~v ) )
   =>

  (printout t "" ?name2 crlf)  
  
  (printout t "Tomar el cubo " ?arf2 crlf)
    (printout t "Ponerlo en el suelo" crlf)
    (assert (on_floor ?arf2 ?name2 )) 
  

    (printout t "Tomar el cubo " ?enf2 crlf)
    (printout t "Ponerlo en el suelo" crlf)
    (assert (on_floor ?enf2 ?name2))  

  (printout t "Tomar el cubo  " ?x crlf)
  (modify ?f2  (ab v) (en v) (ar v) ) 
  (printout t "" ?pila  crlf)
  (printout t "Poner el cubo sobre la pila"crlf)
   
  (if (eq ?abf1 v) then (modify ?f1 (ab ?x)) else
  (if (eq ?enf1 v) then (modify ?f1 (en ?x)) else
  (if (eq ?arf1 v) then (modify ?f1 (ar ?x)) 
  )
  )  
  ) 

  (modify ?g (move v) (on-top-of v))   
)

(defrule  agarrar_de_abajo_con_uno_arriba ""
    ?g<- (goal (move ?x&~v) (on-top-of ?pila&~v ) )
    ?f1 <- (stack (goal v) (name ?pila ) (ab ?abf1 ) (en ?enf1 ) (ar ?arf1 )  )
    ?f2 <- (stack (goal v) (name ?name2 ) (ab ?x )  (en ?enf2&~v ) (ar v ) )
   =>

  (printout t "" ?name2 crlf)  
  


    (printout t "Tomar el cubo " ?enf2 crlf)
    (printout t "Ponerlo en el suelo " crlf)
    (assert (on_floor ?enf2 ?name2 ))  

  (printout t "Tomar el cubo  " ?x crlf)
  (modify ?f2  (ab v) (en v) (ar v) ) 
  (printout t "" ?pila  crlf)
  (printout t "Poner el cubo sobre la pila"crlf)
   
  (if (eq ?abf1 v) then (modify ?f1 (ab ?x)) else
  (if (eq ?enf1 v) then (modify ?f1 (en ?x)) else
  (if (eq ?arf1 v) then (modify ?f1 (ar ?x)) 
  )
  )  
  ) 

  (modify ?g (move v) (on-top-of v))   
)


(defrule  agarrar_de_abajo_sin_nada_arriba ""
    ?g<- (goal (move ?x&~v) (on-top-of ?pila&~v ) )
    ?f1 <- (stack (goal v) (name ?pila ) (ab ?abf1 ) (en ?enf1 ) (ar ?arf1 )  )
    ?f2 <- (stack (goal v) (name ?name2 ) (ab ?x )  (en v ) (ar v ) )
   =>

  (printout t "Ve a la pila " ?name2 crlf)  
  
 

  (printout t "Toma el cubo  " ?x crlf)
  (modify ?f2  (ab v) (en v) (ar v) ) 
  (printout t "Ve a la pila " ?pila  crlf)
  (printout t "Pon el cubo sobre la pila "crlf)
   
  (if (eq ?abf1 v) then (modify ?f1 (ab ?x)) else
  (if (eq ?enf1 v) then (modify ?f1 (en ?x)) else
  (if (eq ?arf1 v) then (modify ?f1 (ar ?x)) 
  )
  )  
  ) 

  (modify ?g (move v) (on-top-of v))   
)

(defrule inicia
  (declare (salience 1))
  =>

  (printout t crlf)
  (printout t "INICIO")
  (printout t crlf ))

;(watch rules)
;(watch facts)
(reset)
(run)
