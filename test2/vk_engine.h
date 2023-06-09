﻿// vulkan_guide.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vk_types.h>
#include <SDL.h>
#include <vector>

class VulkanEngine {
public:
	//initializes everything in the engine
	void init();

	//shuts down the engine
	void cleanup();

	//draw loop
	void draw();

	//run main loop
	void run();

private:
	void init_vulkan();

	//----- other code----
	void init_swapchain();

	//----- other code----
	void init_commands();

	//--- other code ---
	void init_default_renderpass();

	void init_framebuffers();

	//--- other code ---
	void init_sync_structures();

	//
	void handleKeyEvent(SDL_KeyboardEvent* key);

	void PrintModifiers(Uint16 mode);

private:
	bool _isInitialized{ false };
	int _frameNumber{ 0 };
	VkExtent2D _windowExtent{ 1700 , 900 };
	struct SDL_Window* _window{ nullptr };

	// --- omitted ---
	VkInstance _instance; // Vulkan library handle
	VkDebugUtilsMessengerEXT _debug_messenger; // Vulkan debug output handle
	VkPhysicalDevice _chosenGPU; // GPU chosen as the default device
	VkDevice _device; // Vulkan device for commands
	VkSurfaceKHR _surface; // Vulkan window surface

	// --- other code ---
	VkSwapchainKHR _swapchain; // from other articles

	// image format expected by the windowing system
	VkFormat _swapchainImageFormat;

	//array of images from the swapchain
	std::vector<VkImage> _swapchainImages;

	//array of image-views from the swapchain
	std::vector<VkImageView> _swapchainImageViews;

	// ---- other code -----
	VkQueue _graphicsQueue; //queue we will submit to
	uint32_t _graphicsQueueFamily; //family of that queue

	VkCommandPool _commandPool; //the command pool for our commands
	VkCommandBuffer _mainCommandBuffer; //the buffer we will record into

	// ---- other code -----
	VkRenderPass _renderPass;
	std::vector<VkFramebuffer> _framebuffers;

	//--- other code ---
	VkSemaphore _presentSemaphore, _renderSemaphore;
	VkFence _renderFence;

};
