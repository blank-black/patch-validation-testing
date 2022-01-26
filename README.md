# patch-validation-testing

## Replay the issue
Clone this repo in cm docker container.
1. Run command "python3 test.py" will replay the successful case, generate tests_files_convert with converted ktest.
2. Run command "python3 test.py --issue 1" will replay the issue 1, which throw msg "sequence item 2: expected str instance, int found" and generate empty tests_files_convert1.
3. Run command "python3 test.py --issue 2" will replay the issue 2, which throw error "Invalid z_cur_inf" and generate empty tests_files_convert2.