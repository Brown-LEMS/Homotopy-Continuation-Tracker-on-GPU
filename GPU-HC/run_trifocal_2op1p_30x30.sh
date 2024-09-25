#!/bin/bash

solver=magmaHC-main
solver_path=build/bin
yaml_file_path=problems/trifocal_2op1p_30x30

# arguments: ngpus, GPUHC_Type, Use_Runge_Kutta_in_a_Loop, Inline_Eval_Functions, Limit_Loop_Unroll, Truncate_HC_Path_by_Positive_Depths
fname=$yaml_file_path/gpuhc_settings.yaml
write_yaml() {
    echo $fname
    rm -f $fname
    touch $fname
    echo  "%YAML:1.0" >> $fname
    echo  ""          >> $fname
    echo  ""          >> $fname
    echo  "#> Problem Name (must be the same as the problem folder name)" >> $fname
    echo  "problem_name: trifocal_2op1p_30x30" >> $fname
    echo  "problem_print_out_name: Trifocal Relative Pose Problem from Lines at Points" >> $fname
    echo  ""                                          >> $fname
    echo  "#> GPU Settings"                           >> $fname
    echo  "Num_Of_GPUs: " $1                          >> $fname
    echo  ""                                          >> $fname
    echo  "#> GPU-HC Settings"                        >> $fname
    echo  "GPUHC_Max_Steps: 80"                       >> $fname
    echo  "GPUHC_Max_Correction_Steps: 3"             >> $fname
    echo  "GPUHC_Num_Of_Steps_to_Increase_Delta_t: 4" >> $fname
    echo  ""                                          >> $fname

    echo  "#> Problem spec"               >> $fname
    echo  "Num_Of_Vars: 30"               >> $fname
    echo  "Num_Of_Params: 33"             >> $fname
    echo  "Num_Of_Tracks: 312"            >> $fname
    echo  "dHdx_Max_Terms: 8"             >> $fname
    echo  "dHdx_Max_Parts: 5"             >> $fname
    echo  "dHdt_Max_Terms: 16"            >> $fname
    echo  "dHdt_Max_Parts: 6"             >> $fname
    echo  "Max_Order_Of_T: 2"             >> $fname
    echo  "Num_Of_Coeffs_From_Params: 37" >> $fname
    echo  ""                              >> $fname

    echo  "#> Kernel Settings"                                                      >> $fname
    echo  "GPUHC_Type: " $2 "    #> PH or P2C"                                      >> $fname
    echo  "Code_Merged_Optimization: " $3                                           >> $fname
    echo  ""                                                                        >> $fname

    echo  "#> Algorithmic Settings"                  >> $fname
    echo  "Truncate_HC_Path_by_Positive_Depths: " $4 >> $fname
    echo  "Abort_RANSAC_by_Good_Sol: " $5            >> $fname
    echo  ""                                         >> $fname

    echo  "#> RANSAC data"                        >> $fname
    echo  "#RANSAC_Dataset: Synthetic / ICL-NUIM" >> $fname
    echo  "RANSAC_Dataset: ICL-NUIM"              >> $fname
    echo  "#5117"                                 >> $fname
    echo  ""                                      >> $fname

    echo  "#> CPU-HC Settings"                    >> $fname
    echo  "Num_Of_Cores: " $6                     >> $fname
}


write_yaml_version() {
    version=$1
    ngpus=$2
    ncpus=$3
    if [ $version -eq 1 ]; then
        write_yaml $2 "P2C" "false" "false" "false" $3
    fi

    if [ $version -eq 2 ]; then
        write_yaml $2 "PH" "false" "false" "false" $3
    fi

    if [ $version -eq 3 ]; then
        write_yaml $2 "PH" "true" "false" "false" $3
    fi

    if [ $version -eq 4 ]; then
        write_yaml $2 "PH" "true" "true" "false" $3
    fi

    if [ $version -eq 5 ]; then
        write_yaml $2 "PH" "true" "true" "true" $3
    fi
}

# 1st argument ($1) is the version number according to the spreadsheet
# 2nd argument ($2) is the number of GPUs
# 3rd argument ($3) is the number of CPUs
write_yaml_version $1 $2 $3
echo "executing version" $1 "on " $2 " GPUs" " and " $3 " CPUs"
cd $solver_path
./$solver -p trifocal_2op1p_30x30
cd -
