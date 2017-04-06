# Define the solution for SDAccel
create_solution -name viterbi -dir . -force
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:3.0

# Host Compiler Flags
set_property -name host_cflags -value "-g -Wall -D FPGA_DEVICE -D C_KERNEL -I/curr/pengwei/ISCA17/HDLRevisit/AlphaData_Optimization/common"  -objects [current_solution]

# Host Source Files
add_files "../../common/harness.c ../../common/support.c local_support.c"
add_files "../../common/support.h viterbi.h"
set_property file_type "c header files" [get_files "support.h"]
set_property file_type "c header files" [get_files "viterbi.h"]

# Kernel Definition
create_kernel workload -type c
add_files -kernel [get_kernels workload] "viterbi.c"
add_files -kernel [get_kernels workload] "viterbi.h"

# Define Binary Containers
create_opencl_binary workload
set_property region "OCL_REGION_0" [get_opencl_binary workload]
create_compute_unit -opencl_binary [get_opencl_binary workload] -kernel [get_kernels workload] -name k1

# Compile the design for CPU based emulation
compile_emulation -flow cpu -opencl_binary [get_opencl_binary workload]

# Run the compiled application in CPU based emulation mode
run_emulation -flow cpu -args "/curr/pengwei/ISCA17/HDLRevisit/AlphaData_Optimization/viterbi/viterbi_tiling/input.data /curr/pengwei/ISCA17/HDLRevisit/AlphaData_Optimization/viterbi/viterbi_tiling/check.data workload.xclbin"

# Compile the application to run on the accelerator card
build_system

# Package the application binaries
package_system

