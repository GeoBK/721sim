# ./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c473.astar_test.76.0.22.gz pk
# diff -iw stats.2* ./validation_runs/1.txt  >> diff.txt
# rm stats.2*
echo "2.txt" >> diff.txt
./721sim --disambig=1,0,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c473.astar_test.76.0.22.gz pk
diff -iw stats.2* ./validation_runs/2.txt  >> diff.txt
rm stats.2*
echo "3.txt" >> diff.txt
./721sim --disambig=0,1,0 --perf=1,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c473.astar_test.76.0.22.gz pk
diff -iw stats.2* ./validation_runs/3.txt  >> diff.txt
rm stats.2*
./721sim --disambig=1,0,0 --perf=1,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c473.astar_test.76.0.22.gz pk
diff -iw stats.2* ./validation_runs/4.txt  >> diff.txt
rm stats.2*
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c456.hmmer_test.74.0.22.gz pk
diff -iw stats.2* ./validation_runs/5.txt  >> diff.txt
rm stats.2*
./721sim --disambig=1,0,0 --perf=0,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c456.hmmer_test.74.0.22.gz pk
diff -iw stats.2* ./validation_runs/6.txt  >> diff.txt
rm stats.2*
./721sim --disambig=0,1,0 --perf=1,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c456.hmmer_test.74.0.22.gz pk
diff -iw stats.2* ./validation_runs/7.txt  >> diff.txt
rm stats.2*
./721sim --disambig=1,0,0 --perf=1,0,0,0 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c456.hmmer_test.74.0.22.gz pk
diff -iw stats.2* ./validation_runs/8.txt  >> diff.txt
rm stats.2*
./721sim --disambig=1,0,0 --perf=1,0,0,1 --fq=64 --cp=32 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c456.hmmer_test.74.0.22.gz pk
diff -iw stats.2* ./validation_runs/9.txt  >> diff.txt
rm stats.2*
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=8 --al=128 --lsq=64 --iq=32 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c473.astar_test.76.0.22.gz pk
diff -iw stats.2* ./validation_runs/10.txt  >> diff.txt
rm stats.2*
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=8 --al=128 --lsq=64 --iq=32 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c456.hmmer_test.74.0.22.gz pk
diff -iw stats.2* ./validation_runs/11.txt  >> diff.txt
rm stats.2*
./721sim --disambig=1,0,0 --perf=1,0,0,0 --fq=64 --cp=4 --al=128 --lsq=64 --iq=32 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c473.astar_test.76.0.22.gz pk
diff -iw stats.2* ./validation_runs/12.txt  >> diff.txt
rm stats.2*
./721sim --disambig=0,1,0 --perf=0,0,0,0 --fq=64 --cp=4 --al=128 --lsq=64 --iq=32 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c473.astar_test.76.0.22.gz pk
diff -iw stats.2* ./validation_runs/13.txt  >> diff.txt
rm stats.2*
./721sim --disambig=1,0,0 --perf=1,0,0,0 --fq=64 --cp=4 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c456.hmmer_test.74.0.22.gz pk
diff -iw stats.2* ./validation_runs/14.txt  >> diff.txt
rm stats.2*
./721sim --disambig=1,0,0 --perf=1,0,0,1 --fq=64 --cp=4 --al=256 --lsq=128 --iq=64 --iqnp=4 --fw=4 --dw=4 --iw=8 --rw=4 -m2048 -e100000000 -c456.hmmer_test.74.0.22.gz pk
diff -iw stats.2* ./validation_runs/15.txt  >> diff.txt
rm stats.2*


