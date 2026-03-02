## BMP 文件处理初步

### BMP 基本信息

```C++
#pragma pack(push, 1)     // 强制
struct BMPFileHeader {
    uint16_t signature;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t data_offset;
};

struct BMPInfoHeader {
    uint32_t biSize; 
    int32_t biWidth; 
    int32_t biHeight; 
    uint16_t biPlanes; 
    uint16_t biBitcount;
    uint32_t biCompression; 
    uint32_t biSizeImage; 
    int32_t biXPelsPerMeter; 
    int32_t biYPelsPerMeter; 
    uint32_t biClrUsed; 
    uint32_t biClrImportant; 
};
#pragma pack(pop)
```