# patch-validation-testing

## file contents 
tests_files is the dir contains ktest generated from Shadow.

Run test.py can transfer ktest from Shadow format to SEMu format.

ktest_content_muteria.txt is the ktest content of muteria generate.
ktest_content_wei_gen.txt is the ktest content of Wei generate.
Although they are different test, we can see the format of this two test have large diff.


## How to run
In cm docker, run test.py and you can get a dir named tests_files_convert.


## Run semu with seed
I run each seed one by one. To run a seed, you can select a ktest (gen by Muteria or Wei) and move it into an empty dir.
Then use ktest-tool to read the input parameter of this ktest, and use this set of parameter as the symbolic argument of SEMu.



E.g., the ktest I selected has 
args       : ['/work/data/df/437555061ca94fb009cdf0e96b3368f00de95f1e/execution/ctrl/output/latest/testscases_workdir/shadow_se/df.bc', '-sym-args', '0', '1', '23', '-sym-args', '0', '1', '45', '-sym-args', '0', '1', '38', '-sym-args', '0', '1', '1', '-sym-files', '2', '4096', '-sym-stdin', '8', '-sym-stdout']

So I run semu using command:
klee-semu --allow-external-sym-calls --solver-backend z3 --max-memory 4096 --max-time 3600 --libc uclibc --search bfs --semu-precondition-length -2 --semu-checkpoint-window 0 --semu-propagation-proportion 0.25 --semu-minimum-propagation-depth 2 --semu-number-of-tests-per-mutant 5 --only-replay-seeds --seed-out-dir {path-to-seed-dir} -semu-quiet -posix-runtime df.MetaMu.bc -sym-args 0 1 23 -sym-args 0 1 45 -sym-args 0 1 38 -sym-args 0 1 1 -sym-files 2 4096 -sym-stdin 8 -sym-stdout



Or If I want to use the ktest gen by Wei,
The parameter of Wei's ktest:
args       : ['/work/data/df/437555061ca94fb009cdf0e96b3368f00de95f1e/execution/ctrl/output/latest/testscases_workdir/semu/df.bc', '--sym-args', '0', '1', '10', '--sym-args', '0', '2', '2', '--sym-files', '1', '8', '--sym-stdin', '8', '--sym-stdout']

So I run semu using command:
klee-semu --allow-external-sym-calls --solver-backend z3 --max-memory 4096 --max-time 3600 --libc uclibc --search bfs --semu-precondition-length -2 --semu-checkpoint-window 0 --semu-propagation-proportion 0.25 --semu-minimum-propagation-depth 2 --semu-number-of-tests-per-mutant 5 --only-replay-seeds --seed-out-dir {path-to-seed-dir} -semu-quiet -posix-runtime df.MetaMu.bc --sym-args 0 1 10 --sym-args 0 2 2 --sym-files 1 8 --sym-stdin 8 --sym-stdout