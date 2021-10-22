import re,glob
from pathlib import PurePath
def parser(filepath):
  comment=re.compile(r'^//(.+)')
  path=PurePath(filepath)
  filename=path.name
  start=False
  with open (filepath,'r') as cpp:
    with open(f'{path.parent}/{filename}.md','w') as md:
      data=cpp.readlines()
      md.write(f'# {filename}\n ')
      
      for line in data:
      #print(line)
      
        rs=comment.search(line.strip())
        if rs:
          #line=line.capitalize()
          if start:
            line=f'```\n{line.strip()}'
            start=False
         # print(rs.group())
          line=line.replace('//',">  ##### ")
        else:
          if start==False:
            line=f"\n```cpp\n{line}"
            start=True
          else:
            pass
        if line not in ["",'\n']:
          md.write("\n"+line+'\n')
      md.write('\n ```')
      md.write("\n## Complete program  ")
      md.write(f'\n ```cpp \n{"".join(data)} \n```')


def find_files(dir):
  cpp=set()
  md=set()
  for file in glob.glob(dir,recursive=
True):
    if file.endswith('.cpp'):
      cpp.add(file[:-4])
    if file.endswith(".md"):
      md.add(file[:-3])
    #print(file)
  return map(lambda item: f'{item}.cpp',cpp-md)

# files_without_md = find_files('./**')
# for file in files_without_md:
#   parser(file)

      

