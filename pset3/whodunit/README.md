# Questions

## What's `stdint.h`?

A header file which defines new integer types with a fixed width (number of bits). Since the C language does not have a requirement for the size of certain data types (int, long), one can use `stdint.h` to introduces types with predefined memory allocation.  

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The size of some data types in C varies based on the architecture which could create problems in your program (think overflow of a counter). These new data types address this problems by holding a fixed number of bits (width).

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

* BYTE - 1 bytes
* DWORD - 4 bytes
* LONG - 4 bytes
* WORD - 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

* ASCII - BA
* decimal - 6677
* hexadecimal - 0x420x4D

## What's the difference between `bfSize` and `biSize`?

* `bfSize` - The size of the entire bitmap file in bytes, including the image and the headers.
* `biSize` (40 bytes) - The size of the header containing information about the dimensions and colour format (`BITMAPINFOHEADER`).

```
bfSize = biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
bfSize = biSizeImage + sizeof(BITMAPFILEHEADER) + biSize
bfSize = biSizeImage + 14                       + 40
bfSize = biSizeImage + 54
bfSize = biSizeImage + bfOffbits
```

## What does it mean if `biHeight` is negative?

`biHeight` is height of the bitmap, in pixels. Negative `biHeight` means that the bitmap should be read top-down with an origin in the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

A `NULL` pointer return value indicates an error. Some scenarios are:

* File mode or name is invalid.
* Storage allocation request fails.

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

The third parameter specifies the number of elements to be read from the file, each one with a size defined in the second parameter, and stored in the block of memory specified by the first parameter (pointer).

`fread(void *ptr, size_t size, size_t n, FILE *stream)`


## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

(4 - (3 * 3) % 4) % 4 = 3 bytes

## What does `fseek` do?

Changes the file position based on the offset.

## What is `SEEK_CUR`?

Current position of the file pointer. Used by `fseek` to indicate the position from where offset is added.
