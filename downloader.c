#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void download_video(const char *url, const char *quality) {
    char command[512];
    char format[32];

    if(strcmp(quality, "1080p") == 0)
        strcpy(format, "bestvideo[height=1080]+bestaudio/best/[height=1080]");
    else if(strcmp(quality, "720p") == 0)
        strcpy(format, "bestvideo[height=720]+bestaudio/best/[height=720]");
    else if(strcmp(quality, "480p") == 0)
        strcpy(format, "bestvideo[height=480]+bestaudio/best/[height=480]");
    else if(strcmp(quality, "360p") == 0)
        strcpy(format, "bestvideo[height=360]+bestaudio/best/[height=360]");
    else if(strcmp(quality, "240p") == 0)
        strcpy(format, "bestvideo[height=240]+bestaudio/best/[height=240]");
    else{
        printf("Invalid quality option. defaulting to best available option. \n");
        strcpy(format, "best");
    }

    snprintf(command, sizeof(command), "yt-dlp -f \"%s\" -o \"%%(title)s.%%(ext)s\" --progress \"%s\"", format, url);

    printf("\nDownloading video in %s quality...\n", quality);

    int status = system(command);

    if(status == -1) {
        perror("system() failed");
    }
}

int main() {
    char url[256];
    char quality[10];

    // recieve url
    printf("Enter Youtube video URL: ");
    scanf("%255s", url);

    // recieve quality
    printf("Enter resolution (1080p, 720p, 480p, 360p, 240p): ");
    scanf("%9s", quality);

    download_video(url, quality);

    return 0;
}
