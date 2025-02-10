cmake_minimum_required(VERSION 3.20)
project(Win32Game VERSION 1.0 LANGUAGES CXX)

# C++17 사용
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FetchContent 모듈 활성화
include(FetchContent)

# SDL2를 GitHub에서 FetchContent로 가져오기
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.28.0 
)
FetchContent_MakeAvailable(SDL2)

# SDL2_image 가져오기
FetchContent_Declare(
    SDL2_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-2.8.5
)
FetchContent_MakeAvailable(SDL2_image)

# 소스 파일 추가
add_executable(Win32Game src/main.cpp src/app.cpp)

target_include_directories(Win32Game
PRIVATE
include)

# SDL2 라이브러리 연결
target_link_libraries(Win32Game 
SDL2::SDL2 
SDL2::SDL2main
SDL2_image
)
