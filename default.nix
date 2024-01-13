{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
  packages = with pkgs; [
    gnumake
  ];
  nativeBuildInputs = with pkgs; [
    xorg.libX11
    xorg.libX11.dev
    xorg.libXft
    xorg.libXinerama
  ];
}
