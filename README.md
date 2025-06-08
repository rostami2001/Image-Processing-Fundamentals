# Image Processing Fundamentals - Edge Detection Project

**Academic Year**: 2021-2022 (1400 Persian Calendar)  
**Course**: Programming Fundamentals  
**Language**: C  
**Status**: Early academic project (may contain imperfections)

## Project Description
Final project for my first-semester programming course implementing basic image processing operations on BMP files, including:
- Matrix convolution operations
- Edge detection algorithms
- Experimental corner detection (bonus)

## Key Components
### 1. Matrix Convolution
- Applies a kernel matrix to a larger image matrix
- Handles edge cases where kernel cannot fully overlap
- Rounds results to nearest integer

### 2. Edge Detection
- Processes grayscale BMP images (512x512)
- Uses matrix operations to highlight edges
- Outputs modified pixel values (0-255 scale)

### 3. Corner Detection (Experimental)
- Additional challenge attempting to identify corners
- Uses edge detection results as input

## Implementation Notes
- Works with 8-bit grayscale BMP images
- Includes file I/O utilities (`BMPIO.c`) for:
  - `ImTotxt()`: Converts BMP to text matrix
  - `txtToIm()`: Reconstructs BMP from text
- Main algorithm in `finallproject.c`

## Important Disclaimers
1. This represents my **early academic work** from 2020-2021
2. May contain:
   - Suboptimal implementations
   - Unhandled edge cases
   - Code style inconsistencies
3. Preserved as historical record of my programming journey

## Repository Structure
```
├── finallproject.c        - Main convolution/edge detection logic
├── BMPIO.c                - BMP file I/O utilities
├── پروژه دوم.pdf          - Original project PDF (Persian)
└── standard_test_images/  - Sample images (create this folder)
```

## How to Use
1. Place BMP images in `standard_test_images/`
2. Compile and run:
```bash
gcc finallproject.c -o processor -lm
./processor
```
3. Follow prompts to input convolution kernel

## Learning Context
This project demonstrates:
- My first exposure to:
  - Image processing concepts
  - Matrix operations in C
  - File I/O handling
- Early problem-solving approaches
- Foundation for later improvements
