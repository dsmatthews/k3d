#ifndef CUDA_ENTRY_POINTS_H
#define CUDA_ENTRY_POINTS_H

// K-3D
// Copyright (c) 1995-2008, Timothy M. Shead
//
// Contact: tshead@k-3d.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public
// License along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

/** \file
	\author Evan Lezar (evanlezar@gmail.com)
*/


// define the types of kernels supported
#define CUDA_BITMAP_ADD 0x00
#define CUDA_BITMAP_MULTIPLY 0x01
#define CUDA_BITMAP_SUBTRACT 0x02
#define CUDA_BITMAP_COLOR_MONOCHROME 0x03

// define the profiling strings
#define PROFILE_STRING_HOST_TO_DEVICE "Copy from Host to Device"
#define PROFILE_STRING_EXECUTE_KERNEL "Execute Kernel"
#define PROFILE_STRING_DEVICE_TO_HOST "Copy from Device to Host"

// forward declaration of the entry functions
// split the entry functions for timing reasons
extern "C" void CUDA_initialize_device();
extern "C" void bitmap_copy_data_from_host_to_device(const unsigned short *input, int width, int height);
extern "C" void bitmap_arithmetic_kernel_entry(int operation, int width, int height, float value);
extern "C" void bitmap_color_monochrome_kernel_entry(int width, int height, float redWeight, float greenWeight, float blueWeight);
extern "C" void bitmap_copy_data_from_device_to_host(unsigned short *output, int width, int height);
extern "C" void CUDA_cleanup();

#endif // !CUDA_ENTRY_POINTS_H