# Define configuration variables
set project_dir  "./vivado-project-files/reaction_meter_xzy"
set project_name "reaction_meter_xzy"
set synth_run    "synth_1"
set impl_run     "impl_1"

# 1. Open the existing Vivado project
puts "Opening project: $project_name"
open_project "${project_dir}/${project_name}.xpr"

# 2. Reset existing runs to start a fresh compile
puts "Resetting previous runs..."
reset_run $synth_run
reset_run $impl_run

# 3. Launch Synthesis
puts "Launching Synthesis ($synth_run)..."
launch_runs $synth_run -jobs [get_param general.maxThreads]
wait_on_run $synth_run

# Check if synthesis completed successfully
if {[get_property PROGRESS [get_runs $synth_run]] != "100%"} {
    error "ERROR: Synthesis failed!"
}

# 4. Launch Implementation and generate Bitstream
# Project Mode automatically couples bitstream generation via the -to_step flag
puts "Launching Implementation and Bitstream Generation ($impl_run)..."
launch_runs $impl_run -to_step write_bitstream -jobs [get_param general.maxThreads]
wait_on_run $impl_run

# Check if implementation and bitstream generation succeeded
if {[get_property PROGRESS [get_runs $impl_run]] != "100%"} {
    error "ERROR: Implementation/Bitstream generation failed!"
}

puts "SUCCESS: Bitstream generated successfully!"

# 5. Close the project
close_project
