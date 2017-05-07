
import speech_recognition as sr
import re
import serial

usb = serial.Serial('/dev/ttyACM0', 9600)

def match_result(pattern, order):
   
    if re.match(pattern, order):
        return True
    else:
        return False

def decide(order):
   
    if order == "stop":
        print('stopping')
        usb.write(b's')
        
    elif order == "forward":
        print("going forward")
        usb.write(b'f')
        
    elif order == "backward":
        print("going backward")
        usb.write(b'b')
        
    elif order == "left":
        print("turning left")
        usb.write(b'l')
        
    elif order == "right":
        print("turning right")
        usb.write(b'r')
        
    else:
        print("I did not understand")


if __name__ == '__main__':
    
    #Un dictionnaire pour nos modèles d'expression régulière
    regex_dict = {r"^fo": "forward", r"(ba|th)": "backward", r"(st|o|it|th)": "stop"
                  , r"(ye|le)": "left", r"(ri|al|so)": "right"}
    
    #Obtenir de l'audio du microphone
    engine = sr.Recognizer()
    with sr.Microphone() as source:
        print("Command me!")
        audio = engine.listen(source)
    
    #Reconnaissant le discours et la décision
    t = engine.recognize_sphinx(audio)
    for i in regex_dict:
        if match_result(i, t):
            decide(regex_dict[i])
            break
        else: pass
            
            
    
    
