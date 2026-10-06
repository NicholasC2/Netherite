when defined(sdl):
  import backend/sdl
elif defined(n3ds):
  import backend/n3ds
else:
  import backend/sdl

proc main() =
  var backend = initBackend()

  defer:
    backend.shutdown()

  while true:
    if(not backend.poll()):
      break

    backend.render()

main()
