import sdl3
import nimgl/opengl

import strformat

type
  SDL3Backend* = object
    window: SDL_Window
    glContext: SDL_GLContext

proc initBackend*(): SDL3Backend =
  if not SDL_Init(SDL_INIT_VIDEO):
    discard SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_Init failed", SDL_GetError(), nil)
    raise newException(OSError, fmt"SDL_Init failed: {SDL_GetError()}")

  let window = SDL_CreateWindow("Netherite Client", 960, 540, SDL_WINDOW_RESIZABLE or SDL_WINDOW_OPENGL)

  if window == nil:
    discard SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_CreateWindow failed", SDL_GetError(), nil)
    raise newException(OSError, fmt"SDL_CreateWindow failed: {SDL_GetError()}")

  let glContext = SDL_GL_CreateContext(window)

  if glContext == nil:
    SDL_DestroyWindow(window)
    discard SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_GL_CreateContext failed", SDL_GetError(), nil)
    raise newException(OSError, fmt"SDL_GL_CreateContext failed: {SDL_GetError()}")

  discard SDL_GL_MakeCurrent(window, glContext)

  if not glInit():
    SDL_GL_DestroyContext(glContext)
    SDL_DestroyWindow(window)
    discard SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "OpenGL initialization failed", nil, nil)
    raise newException(OSError, "OpenGL initialization failed")

  result = SDL3Backend(
    window: window,
    glContext: glContext
  )

proc poll*(backend: var SDL3Backend): bool =
  var event: SDL_Event

  while SDL_PollEvent(event):
    case event.type
    of SDL_EVENT_QUIT:
      return false
    else:
      discard

  return true

proc render*(backend: var SDL3Backend) =
  glClearColor(0, 0, 0, 1.0)
  glClear(GL_COLOR_BUFFER_BIT)

  discard SDL_GL_SwapWindow(backend.window)

proc shutdown*(backend: var SDL3Backend) =
  SDL_GL_DestroyContext(backend.glContext)
  SDL_DestroyWindow(backend.window)
  SDL_Quit()
