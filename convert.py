from Parser.parser import *
import argparse
 
 
# Initialize parser
parser1 = argparse.ArgumentParser()
 
# Adding optional argument
parser1.add_argument("--f",nargs="+",help="enter files")
 
# Read arguments from command line
args = parser1.parse_args()
 
if args.f:
    files_without_md = args.f
else: 
  files_without_md = find_files('./**')


for file in files_without_md:
  parser(file)
print("...Done")