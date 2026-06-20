set export := true
OBJCACHE := "sccache"

build:
    vivado -mode batch -source build_basys3.tcl

upload f="vivado-project-files/reaction_meter_xzy/reaction_meter_xzy.runs/impl_1/top_basys3.bit":
    openFPGALoader -b basys3 --freq 10M --bitstream {{f}}

surfer fst="./build/vcd.fst":
    surfer {{fst}}

test tb="top_basys3": 
  verilator  -I./src/ -I./tests --cc {{tb}}.sv --trace-fst --build -CFLAGS -O0 -CFLAGS -fuse-ld=mold --verilate-jobs 16 --threads 4 --hierarchical --timing --binary --Mdir {{tb}}_obj/ -Wno-ASCRANGE -Wno-SELRANGE -Wno-MULTIDRIVEN -Wno-IMPLICITSTATIC -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC
  cd ./{{tb}}_obj/ && ./V{{tb}}

verilator tb:
    verilator --binary --build -j \
      -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
      -I./src \
      -o tb_{{tb}} \
      ./tests/tb_{{tb}}.sv ./src/{{tb}}.sv
    ./obj_dir/tb_{{tb}} +trace

all:
    just build
    just upload
