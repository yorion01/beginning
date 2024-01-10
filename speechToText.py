import speech_recognition as sr
r = sr.Recognizer()
with sr.Microphone() as source:
    print("I'm listening.")
    audio = r.listen(source)#마이크로 음성 듣기

try:
    text = r.recognize_google_cloud(audio,language='en_US')
    print(text)
except sr.UnknownValueError:
    print("인식 실패")
except sr.RequestError as e:
    print("요청 실패: {0}".format(e))#API 키 오류, 네트워크 단절 등