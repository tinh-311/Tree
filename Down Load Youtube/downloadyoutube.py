from pytube import YouTube
url = "https://www.youtube.com/watch?v=bTFoZBIIu4E"
yt = YouTube(url).streams.filter(progressive=True,file_extension='mp4').first().download()

print(yt)