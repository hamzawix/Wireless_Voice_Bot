'''
Created on Mar 4, 2017

@author: hamzawix
'''

import speech_recognition as sr
import re

def match_result(pattern, order):
   
    if re.match(pattern, order):
        return True
    else:
        return False
    
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
    
    #A dictionary for our regular expression patterns
    regex_dict = {r"^fo": "forward", r"(ba|th)": "backward", r"(st|o|it|th)": "stop"
                  , r"(ye|le)": "left", r"(ri|al|so)": "right"}
    
    #Getting audio from microphone
    engine = sr.Recognizer()
    with sr.Microphone() as source:
        print("Command me!")
        audio = engine.listen(source)
    
    #Recognising speech and deciding
    t = engine.recognize_sphinx(audio)
    for i in regex_dict:
        if match_result(i, t):
            decide(regex_dict[i])
            break
        else: pass
            
            
    
    
