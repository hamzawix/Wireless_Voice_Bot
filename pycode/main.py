'''
Created on Mar 4, 2017

@author: hamzawix
'''

import speech_recognition as sr

#Getting audio from microphone
r = sr.Recognizer()
with sr.Microphone() as source:
    print("Command me!")
    audio = r.listen(source)

#Recognising speech
try:
    print("I think you said: {}".format(r.recognize_sphinx(audio)))
          
except sr.UnknownValueError:
    print("I coudn't understand you!")
    
except sr.RequestError as e:
    print("an error; {}".format(e))
