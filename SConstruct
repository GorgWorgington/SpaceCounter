import os

platform = ARGUMENTS.get("platform")

enabled_tools = ['default', 'qt5', 'compilation_db']

# Defines the command-line option "--win64"
AddOption('--win64',
          action='store_true',
          help='cross-compiles for windows',
          default=False)
 

env = Environment(
    tools=enabled_tools,
    ENV = {'PATH' : os.environ['PATH'], 'PKG_CONFIG_PATH' : os.environ['PKG_CONFIG_PATH']}
    )
env.EnableQt5Modules(['QtGui', 'QtWidgets', 'QtCore'])

# If SCons was called with '--win64'
if GetOption('win64'):
    env['CXX']='i686-w64-mingw32-g++'
else:
    env['CXX']='c++'

env.Append(CPPPATH = ['./'])
env.Append(CPPFLAGS = ['-fPIC'])

env['COMPILATIONDB_USE_ABSPATH'] = True
env.CompilationDatabase()

env.Uic5(Glob("*.ui"))

env.Program("SpaceCounter", Glob("*.cpp"))