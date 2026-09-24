using System;
using SDL3;

internal class Program
{
    static void Main(string[] args)
    {
        if (!SDL.Init(SDL.InitFlags.Video))
        {
            Console.WriteLine("[SDL] Init failed: " + SDL.GetError());
            return;
        }

        Console.WriteLine("[SDL] Initialized successfully");

        nint window = SDL.CreateWindow(
            "Netherite.Client",
            640,
            480,
            SDL.WindowFlags.OpenGL
        );

        if (window == nint.Zero)
        {
            Console.WriteLine("[SDL] Window creation failed: " + SDL.GetError());
            SDL.Quit();
            return;
        }

        bool running = true;

        while(running) {
            while(SDL.PollEvent(out SDL.Event e)) {
                if (e.Type == SDL) {
                    running = false;
                }
            }
        }

        SDL.DestroyWindow(window);
        SDL.Quit();
    }
}
