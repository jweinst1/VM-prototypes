import subprocess
import sys

# Script to compile single file c executables with gcc


def main():
    filename = sys.argv[1]
    cmd_str = "gcc -Wall %s.c -o bin/%s" % (filename, filename)
    subprocess.call("mkdir -p bin", shell=True)
    subprocess.call(cmd_str, shell=True)
    print "Compiled file %s." % (filename)


if __name__ == '__main__':
    main()
