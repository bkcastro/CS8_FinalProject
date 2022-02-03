cmake_minimum_required(VERSION 3.14)
project(CS8_FinalProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Bar.cpp Bar.h Tools/Box.cpp Tools/Box.h Grid.cpp Grid.h SelectionSort.cpp SelectionSort.h GridBox.cpp GridBox.h Delay.h Menu.cpp Menu.h Images/Images.cpp Images/Images.h Text/Letter.cpp Text/Letter.h Fonts/Fonts.cpp Fonts/Fonts.h Tools/Colors.cpp Tools/Colors.h Text/HighLightText.cpp Text/HighLightText.h Tools/ObjectStates.h Tools/States.cpp Tools/States.h Program.cpp Program.h Tools/MouseEvents.cpp Tools/MouseEvents.h MainProgram.cpp MainProgram.h Algorithms.cpp Algorithms.h GUI_Components.cpp GUI_Components.h Snapshot.h SnapshotInterface.h Dropdown/MenuBox.cpp Dropdown/MenuBox.h Dropdown/MenuBar.cpp Dropdown/MenuBar.h Dropdown/DropdownMenu.cpp Dropdown/DropdownMenu.h Dropdown/ItemList.cpp Dropdown/ItemList.h Dropdown/Item.cpp Dropdown/Item.h Dropdown/Helper.cpp Dropdown/Helper.h Dropdown/FileItem.cpp Dropdown/FileItem.h Dropdown/FileNode.cpp Dropdown/FileNode.h Dropdown/FileTree.cpp Dropdown/FileTree.h Tools/PlayButton.cpp Tools/PlayButton.h Dropdown/ContainMenus.cpp Dropdown/ContainMenus.h Tools/Slider.cpp Tools/Slider.h Tools/ColorPicker.cpp Tools/ColorPicker.h Text/MultiText.cpp Text/MultiText.h Text/Cursor.cpp Text/Cursor.h Text/KeyShortcut.cpp Text/KeyShortcut.h Text/SpecialWords.cpp Text/SpecialWords.h Text/TempHistory.h LinkList/Node.h LinkList/Node_Iterator.cpp LinkList/Node_Iterator.h LinkList/LinkList.cpp LinkList/LinkList.h Tools/Task.cpp Tools/Task.h Tools/TaskObjects.h Tools/TaskSnapshot.h Tools/AlgorithmStates.h Tools/TaskHelper.cpp Tools/TaskHelper.h Text/TextBox.cpp Text/TextBox.h SetMaxSystem.cpp SetMaxSystem.h Delay.cpp BubbleSort.cpp BubbleSort.h MergeSort.cpp MergeSort.h FileInterface.cpp FileInterface.h Dropdown/hack.cpp Dropdown/hack.h)
add_executable(CS8_FinalProject ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(CS8_FinalProject sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
