import argparse
import os
import time
import signal
import re
import multiprocessing
from muteria.drivers.testgeneration.testcase_formats.ktest.utils import \
                                                    ConvertCollectKtestsSeeds

j = {
    "": [["--sym-args", "0", "1", "10"], ["--sym-args", "0", "2", "2"], ["--sym-files", "1", "8"], ["--sym-stdin", "8"], ["--sym-stdout"]],
    "dd": [["--sym-args", "0", "3", "10"], ["--sym-files", "1", "8"], ["--sym-stdin", "8"], ["--sym-stdout"]],
    "dircolors": [["--sym-args", "0", "3", "10"], ["--sym-files", "2", "12"], ["--sym-stdin", "12"], ["--sym-stdout"]],
    "echo": [["--sym-args", "0", "4", "300"], ["--sym-files", "2", "30"], ["--sym-stdin", "30"], ["--sym-stdout"]],
    "expr": [["--sym-args", "0", "1", "10"], ["--sym-args", "0", "3", "2"], ["--sym-stdout"]],
    "mknod": [["--sym-args", "0", "1", "10"], ["--sym-args", "0", "3", "2"], ["--sym-files", "1", "8"], ["--sym-stdin", "8"], ["--sym-stdout"]],
    "od": [["--sym-args", "0", "3", "10"], ["--sym-files", "2", "12"], ["--sym-stdin", "12"], ["--sym-stdout"]],
    "pathchk": [["--sym-args", "0", "1", "2"], ["--sym-args", "0", "1", "300"], ["--sym-files", "1", "8"], ["--sym-stdin", "8"], ["--sym-stdout"]],
    "printf": [["--sym-args", "0", "3", "10"], ["--sym-files", "2", "12"], ["--sym-stdin", "12"], ["--sym-stdout"]]
}

def convert(path, program, test_dir, result):
    try:
        if os.path.isfile(os.path.join(path, result + '.tar.gz')):
            os.system('rm -r ' + os.path.join(path, result + '.tar.gz'))
        if os.path.isdir(os.path.join(path, result)):
            os.system('rm -r ' + os.path.join(path, result))
        if not os.path.isdir(os.path.join(path, test_dir)):
            print("Can't find test_dir " + path + ' ' + test_dir)
            return -1
        args = ''
        if program in j:
            args = j[program]
        else:
            args = [["--sym-args", "0", "1", "10"], ["--sym-args", "0", "2", "2"], ["--sym-files", "1", "8"],
                    ["--sym-stdin", "8"], ["--sym-stdout"]]
        ccks = ConvertCollectKtestsSeeds(custom_binary_dir=None)
        # print(os.path.join(path, result))
        # print(os.path.join(path, test_dir))
        # print(args)
        ccks.generate_seeds_from_various_ktests(
            os.path.join(path, result),
            os.path.join(path, test_dir),
            # src_new_klee_ktest_dir_or_sym_args=["--sym-args 0 1 10", "--sym-args 0 2 2"], \
            src_new_klee_ktest_dir_or_sym_args=args,
            klee_ktest_is_sym_args=True,
            compress_dest=False,
            skip_failure=True)
    except Exception as e:
        print(e)


convert('.', 'df', 'tests_files', 'tests_files_convert') 
