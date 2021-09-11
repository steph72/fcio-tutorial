import os

env = Environment(
    ENV={'PATH': os.environ['PATH']},
    CPPPATH='mega65-libc/cc65/include',
    CC='cl65')

test = env.Program('bin/fcdemo.c64', [
    'test.c',
    'mega65-libc/cc65/src/memory.c',
    'mega65-libc/cc65/src/fcio.c'
])

buildDiscAction = Action('tools/buildDisc.sh')
env.AddPostAction(test, buildDiscAction)


