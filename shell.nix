let
  pkgs = import <nixpkgs> {};
in
  pkgs.mkShell {
    nativeBuildInputs = [
      pkgs.gdb
      pkgs.pkg-config
      pkgs.cmake
      pkgs.meson
      pkgs.ninja
    ];

    buildInputs = [
      pkgs.leptonica
      pkgs.tesseract4
    ];
  }
