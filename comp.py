import subprocess
import sys

# Script to compile single file c executables with gcc


def main():
    filename = sys.argv[1]
    print filename
    cmd_str = "gcc -Wall %s.c -o bin/%s" % (filename, filename)
    subprocess.call(cmd_str)
    print "Compiled file %s." % (filename)


if __name__ == '__main__':
    main()
