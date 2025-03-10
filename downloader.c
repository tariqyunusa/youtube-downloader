#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void download_video(const char *url, const char *quality) {
    char command[512];
    char format[64]; 

    if (strcmp(quality, "1080p") == 0)
        strcpy(format, "bestvideo[height=1080]+bestaudio/best[height=1080]");
    else if (strcmp(quality, "720p") == 0)
        strcpy(format, "bestvideo[height=720]+bestaudio/best[height=720]");
    else if (strcmp(quality, "480p") == 0)
        strcpy(format, "bestvideo[height=480]+bestaudio/best[height=480]");
    else if (strcmp(quality, "360p") == 0)
        strcpy(format, "bestvideo[height=360]+bestaudio/best[height=360]");
    else if (strcmp(quality, "240p") == 0)
        strcpy(format, "bestvideo[height=240]+bestaudio/best[height=240]");
    else {
        printf("Invalid quality option. Defaulting to best available quality.\n");
        strcpy(format, "bestvideo+bestaudio/best");  
    }

    // Construct yt-dlp command
    snprintf(command, sizeof(command), "yt-dlp -f \"%s\" -o \"%%(title)s.%%(ext)s\" --progress \"%s\"", format, url);

    printf("\n📥 Downloading video in %s quality...\n", quality);

    int status = system(command);
    
    if (status == -1) {
        perror("Error: Failed to execute yt-dlp");
    } else {
        printf("\nDownload completed successfully!\n");
    }
}

int main() {
    char url[512];  
    char quality[10];

    // Get YouTube URL
    printf("Enter YouTube video URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0;  // Remove newline character

    // Get quality
    printf("Enter resolution (1080p, 720p, 480p, 360p, 240p): ");
    fgets(quality, sizeof(quality), stdin);
    quality[strcspn(quality, "\n")] = 0;  

    // Start download
    download_video(url, quality);

    return 0;
}
