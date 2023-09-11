set_project("ModernRobotics")
set_version("0.0.1")

add_requires("eigen 3.4.0", {system = false, configs = {shared = false, debug = true, cxflags = "-fPIC"}})

add_includedirs("include")

target("modern_robotics")
    set_kind("static")
    add_headerfiles("include/*.h")
    if is_plat("windows") then
        add_cxxflags("/bigobj")
    end
    add_files("src/*.cpp")
    add_packages("eigen")
target_end()

target("test")
    set_kind("binary")
    add_files("main.cpp")
    add_packages("eigen")
    add_deps("modern_robotics")
target_end()
