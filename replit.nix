{ pkgs }: {
  deps = [
    pkgs.run
    pkgs.clang-tools
    pkgs.clang
    pkgs.gnumake
    pkgs.cmake
    # pkgs.opencode          
  ];
}