YouTube Video Downloader (C CLI Tool)

A simple command-line tool written in C that downloads YouTube videos at a specified resolution using yt-dlp.

🚀 Features

Download YouTube videos in resolutions: 1080p, 720p, 480p, 360p, 240p

Automatically selects the best audio and video format for the chosen resolution

Displays progress during the download

Error handling for invalid resolutions

📌 Requirements

Windows with GCC (MinGW) installed

yt-dlp installed and accessible from the command line

🛠 Installation

1️⃣ Install yt-dlp

If you don’t have yt-dlp, install it using:
```sh
pip install -U yt-dlp
```
Or download the binary from: yt-dlp Official Site

2️⃣ Compile the C Program
```sh

gcc downloader.c -o downloader.exe

```
3️⃣ Run the Program

Option 1: Interactive Mode

```sh
./downloader.exe
```

Then, enter the YouTube URL and resolution when prompted.

Option 2: Direct Execution from Command Line
```sh

./downloader.exe "<YouTube_URL>" <Resolution>

```
Example:

```sh
./downloader.exe "https://www.youtube.com/watch?v=1fZeBafD1nw" 720p

```

📝 Usage Example

```sh
Enter YouTube video URL: https://www.youtube.com/watch?v=1fZeBafD1nw
Enter resolution (1080p, 720p, 480p, 360p, 240p): 720p
📥 Downloading video in 720p quality...
✅ Download completed successfully!

```
📂 Optional: Add to System PATH

If you want to run downloader.exe from anywhere in the terminal:

Move downloader.exe to C:\Tools\ (or any preferred location)

Add C:\Tools\ to your system PATH (Environment Variables)

Now, you can run:

```sh
downloader.exe "<YouTube_URL>" <Resolution>

```
❌ Troubleshooting

"yt-dlp: command not found" → Ensure yt-dlp is installed and added to your system PATH.

"gcc: command not found" → Install MinGW and add it to your PATH.

Download fails? → Try updating yt-dlp:

```sh
yt-dlp -U
```