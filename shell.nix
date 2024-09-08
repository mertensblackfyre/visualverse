let
  pkgs = import <nixpkgs> {};
in
  pkgs.mkShell {
    packages = [
      pkgs.leptonica
      pkgs.gcc
      pkgs.gdb
      pkgs.tesseract4
      pkgs.cmake
      pkgs.meson
      pkgs.ninja
    ];
  }
