#ifndef STRUCTURES_H
#define STRUCTURES_H

#pragma pack(push, 1)

typedef struct {
	char signature[2];              //'B' 'M' 
	unsigned __int32 file_size;              // File size in bytes
	unsigned __int16 reserved[2];         // unused
	unsigned __int32 offset;     // Offset to image data in bytes from beginning of file
}FILEHEADER;


typedef struct
{
	unsigned __int32 header_size;   
	__int32  width_px;          // Width of the 
	__int32  height_px;         // Height of image
	unsigned __int16  planes;        // Number of color planes
	unsigned __int16  bit_count;    // Bits per pixel
	unsigned __int32  compression;       // Compression type
	unsigned __int32  img_size;  // Image size in bytes
	__int32  x_res;  // Pixels per meter
	__int32  y_res;  // Pixels per meter
	unsigned __int32 color_used;        // Number of colors
	unsigned __int32 important_colors;  // Important colors 0=all
} IMGHEADER;

typedef struct
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
}PIXEL;

typedef struct
{
	FILEHEADER fhead;
	IMGHEADER imghead;
	PIXEL *imgarray;

}BMP;
#pragma pack(pop)
#endif 
