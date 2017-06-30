#ifndef GYT_COMMON_H
#define GYT_COMMON_H

//#define CAPACITIVE_SCREEN

//#define SYS_ADVANTECH
//#define SYS_KONTRON

#define TITLE_HEIGHT 40

#ifdef GY_GLOBAL
#define GY_GLOBAL_EXT
#else
#define GY_GLOBAL_EXT extern
#endif

GY_GLOBAL_EXT char BACKLIGHT_NAME[32];
GY_GLOBAL_EXT unsigned int LCD_WIDTH;
GY_GLOBAL_EXT unsigned int LCD_HEIGHT;

#pragma pack(push)
#pragma pack(1)

typedef struct applyCMD {
    unsigned char head;
    unsigned char size;
    unsigned char type;
    unsigned char snum;
    unsigned char cmdw;
    unsigned char csum;
    unsigned char tail;
}applyCMD;

typedef struct controlCMD {
    unsigned char head;
    unsigned char size;
    unsigned char type;
    unsigned char snum;
    unsigned char cmdw;
    unsigned char mode; // 0x00: Standard, 0x01: Debug
    unsigned char reserve1[2];
    float fanSpeed;
    unsigned char reserve2[4];
    unsigned char csum;
    unsigned char tail;
}controlCMD;

typedef struct readStatusCMD {
    unsigned char head;
    unsigned char size;
    unsigned char type;
    unsigned char snum;
    unsigned char cmdw;
    unsigned char serialStatus; // 0x00: Abnormal, 0x01: Normal
    unsigned char reserve1[2];
    float temperature1;
    float temperature2;
    float fanSpeed;
    unsigned char reserve2[2];
    unsigned char csum;
    unsigned char tail;
 }readStatusCMD;

typedef struct readVersionCMD {
     unsigned char head;
     unsigned char size;
     unsigned char type;
     unsigned char snum;
     unsigned char cmdw;
     unsigned char reserve1[3];
     unsigned char firmwareVer[4];
     unsigned char hardwareVer[2];
     unsigned char reserve2[2];
     unsigned char reserve3[8];
     unsigned char csum;
     unsigned char tail;
}readVersionCMD;

#pragma pack(pop)


#ifdef __cplusplus
extern "C"{
#endif

unsigned char calcCheckSum(unsigned char *data, unsigned int len);

void detectDevices(void);

#ifdef __cplusplus
}
#endif


#endif // GYT_COMMON_H
