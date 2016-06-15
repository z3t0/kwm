#ifndef WINDOW_H
#define WINDOW_H

#include "types.h"
#include "axlib/display.h"
#include "axlib/window.h"

void CreateWindowNodeTree(ax_display *Display);
void LoadWindowNodeTree(ax_display *Display, std::string Layout);
void ResetWindowNodeTree(ax_display *Display, space_tiling_option Mode);
void AddWindowToNodeTree(ax_display *Display, uint32_t WindowID);
void RemoveWindowFromNodeTree(ax_display *Display, uint32_t WindowID);
void RebalanceNodeTree(ax_display *Display);

ax_window *GetWindowByID(uint32_t WindowID);
void GetCenterOfWindow(ax_window *Window, int *X, int *Y);
bool WindowIsInDirection(ax_window *WindowA, ax_window *WindowB, int Degrees);
bool FindClosestWindow(int Degrees, ax_window **ClosestWindow, bool Wrap);

/* TODO(koekeishiya): PARTIALLY LOOKED AT */
void FocusWindowByID(uint32_t WindowID);
void ToggleWindowFloating(uint32_t WindowID, bool Center);
void ToggleFocusedWindowFloating();

/* TODO(koekeishiya): NOT YET LOOKED AT */
extern int GetSpaceNumberFromCGSpaceID(screen_info *Screen, int CGSpaceID);
extern int GetActiveSpaceOfDisplay(screen_info *Screen);

bool IsFocusedWindowFloating();
bool IsWindowFloating(int WindowID, int *Index);
bool IsAnyWindowBelowCursor();
bool IsWindowBelowCursor(window_info *Window);
bool IsWindowOnActiveSpace(int WindowID);
bool WindowsAreEqual(window_info *Window, window_info *Match);

void ClearFocusedWindow();
bool FocusWindowOfOSX();

void UpdateWindowTree();
std::vector<window_info> FilterWindowListAllDisplays();
bool FilterWindowList(screen_info *Screen);
void UpdateActiveWindowList(screen_info *Screen);
void CreateWindowNodeTree(screen_info *Screen, std::vector<window_info*> *Windows);
void ShouldWindowNodeTreeUpdate(screen_info *Screen);
void AddWindowToTreeOfUnfocusedMonitor(screen_info *Screen, window_info *Window);

std::vector<window_info*> GetAllWindowsNotInTree(std::vector<int> &WindowIDsInTree);
std::vector<int> GetAllWindowIDsToRemoveFromTree(std::vector<int> &WindowIDsInTree);

void ShouldBSPTreeUpdate(screen_info *Screen, space_info *Space);
void AddWindowToBSPTree(screen_info *Screen, int WindowID);
void AddWindowToBSPTree();
void RemoveWindowFromBSPTree(screen_info *Screen, int WindowID, bool Center, bool UpdateFocus);
void RemoveWindowFromBSPTree();

void ShouldMonocleTreeUpdate(screen_info *Screen, space_info *Space);
void AddWindowToMonocleTree(screen_info *Screen, int WindowID);
void RemoveWindowFromMonocleTree(screen_info *Screen, int WindowID, bool Center, bool UpdateFocus);

void ToggleFocusedWindowParentContainer();
void ToggleFocusedWindowFullscreen();
bool IsWindowFullscreen(window_info *Window);
bool IsWindowParentContainer(window_info *Window);
void LockWindowToContainerSize(window_info *Window);

void DetachAndReinsertWindow(unsigned int WindowID, int Degrees);
void SwapFocusedWindowWithMarked();
void SwapFocusedWindowDirected(int Degrees);
void SwapFocusedWindowWithNearest(int Shift);
void MoveCursorToCenterOfWindow(window_info *Window);
void MoveCursorToCenterOfFocusedWindow();
void FocusWindowByID(int WindowID);
void ShiftWindowFocus(int Shift);
void ShiftSubTreeWindowFocus(int Shift);
void ShiftWindowFocusDirected(int Degrees);
bool FindClosestWindow(int Degrees, window_info *Target, bool Wrap);
double GetWindowDistance(window_info *A, window_info *B, int Degrees, bool Wrap);
void GetCenterOfWindow(window_info *Window, int *X, int *Y);
bool WindowIsInDirection(window_info *A, window_info *B, int Degrees);

void ClearMarkedWindow();
void MarkWindowContainer(ax_window *Window);
void MarkFocusedWindowContainer();

void SetWindowRefFocus(AXUIElementRef WindowRef);
void SetKwmFocus(AXUIElementRef WindowRef);
void SetWindowFocus(window_info *Window);
void SetWindowFocusByNode(tree_node *Node);
void SetWindowFocusByNode(link_node *Link);

bool IsWindowTilable(window_info *Window);
bool IsWindowTilable(AXUIElementRef WindowRef);
void CenterWindowInsideNodeContainer(AXUIElementRef WindowRef, int *Xptr, int *Yptr, int *Wptr, int *Hptr);

void SetWindowDimensions(AXUIElementRef WindowRef, window_info *Window, int X, int Y, int Width, int Height);
void CenterWindow(screen_info *Screen, window_info *Window);
void MoveFloatingWindow(int X, int Y);

window_info GetWindowByRef(AXUIElementRef WindowRef);
window_info *GetWindowByID(int WindowID);
CGPoint GetWindowPos(window_info *Window);
void GetWindowInfo(const void *Key, const void *Value, void *Context);
bool GetWindowRole(window_info *Window, CFTypeRef *Role, CFTypeRef *SubRole);
bool GetWindowRef(window_info *Window, AXUIElementRef *WindowRef);

#endif
