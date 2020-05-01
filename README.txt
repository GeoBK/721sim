Simulator can be built in the regular manner by just running make. No additional steps are necessary.

To run the microbenchmark with a fully associative REP execute the following command 
./721sim --perf=0,0,0,1 --repassoc=2048 pk double_loop

To run the microbenchmark with associativity set to 8 run 
./721sim --perf=0,0,0,1 pk double_loop

The double_loop binary should be present under the 'uarchsim' folder itself.

Two new flags have been added in the simulator which are --repassoc and --repsize.
astar
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4  --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c473.astar_test.76.0.22.gz pk
hmmer
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c456.hmmer_test.74.0.22.gz pk
bzip2
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c401.bzip2_dryer_test.53.0.35.gz pk
bwaves
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c410.bwaves_test.370.0.45.gz pk
MCF
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c429.mcf_test.7.0.38.gz pk
libquantum
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c462.libquantum_ref.13679.0.28.gz pk