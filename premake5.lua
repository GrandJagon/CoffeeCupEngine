workspace "CoffeeCupEngine"
    architecture 'x64'
    configurations { "Debug", "Release"}
    startproject "CoffeeCupEngine"

    outputdir = "%{cfg.buildcgf}-%{cfg.system}-%{cfg.architecture}"

   include "CoffeeCupEngine"