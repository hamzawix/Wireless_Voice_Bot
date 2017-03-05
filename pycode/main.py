'''
Created on Mar 4, 2017

@author: hamzawix
'''

import speech_recognition as sr

def decide(order):
    """
    This is a function that takes the returned text from the recognizer
    as an argument and decides where the robot should go.
    """
    if order == "stop":
        print("stoping")
        
    elif order == "forward":
        print("going forward")
        
    elif order == "backward":
        print("going backward")
        
    elif order == "left":
        print("turning left")
        
    elif order == "right":
        print("turning right")
        
    else:
        print("I did not understand")


if __name__ == '__main__':
    
    #Getting audio from microphone
    engine = sr.Recognizer()
    with sr.Microphone() as source:
        print("Command me!")
        audio = engine.listen(source)
    
    #Recognising speech and deciding
    try:
        b = engine.recognize_sphinx(audio)
        decide(b)
        #print("I think you said: {}".format(b))
              
    except sr.UnknownValueError:
        print("I coudn't understand you!")    
    


    
