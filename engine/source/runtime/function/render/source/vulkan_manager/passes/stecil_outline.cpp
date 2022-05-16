#include "runtime/function/render/include/render/vulkan_manager/vulkan_common.h"
#include "runtime/function/render/include/render/vulkan_manager/vulkan_mesh.h"
#include "runtime/function/render/include/render/vulkan_manager/vulkan_misc.h"
#include "runtime/function/render/include/render/vulkan_manager/vulkan_passes.h"
#include "runtime/function/render/include/render/vulkan_manager/vulkan_util.h"

#include <stencil_solid_frag.h>

namespace Pilot {

    void PStencilOutlinePass::initialize(VkRenderPass render_pass, VkImageView input_attachment)
    {
        _framebuffer.render_pass = render_pass;
        setupDescriptorSetLayout();
        setupPipelines();
        setupDescriptorSet();
        updateAfterFramebufferRecreate(input_attachment);
    }

    void PStencilOutlinePass::setupDescriptorSetLayout()
    {
        _descriptor_infos.resize(1);

        VkDescriptorSetLayoutBinding post_process_global_layout_bindings[1] = {};

        VkDescriptorSetLayoutBinding& post_process_global_layout_input_attachment_binding =
            post_process_global_layout_bindings[0];
        post_process_global_layout_input_attachment_binding.binding = 0;
        post_process_global_layout_input_attachment_binding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        post_process_global_layout_input_attachment_binding.descriptorCount = 1;
        post_process_global_layout_input_attachment_binding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;

        VkDescriptorSetLayoutCreateInfo post_process_global_layout_create_info;
        post_process_global_layout_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        post_process_global_layout_create_info.pNext = NULL;
        post_process_global_layout_create_info.flags = 0;
        post_process_global_layout_create_info.bindingCount =
            sizeof(post_process_global_layout_bindings) / sizeof(post_process_global_layout_bindings[0]);
        post_process_global_layout_create_info.pBindings = post_process_global_layout_bindings;

        if (VK_SUCCESS != vkCreateDescriptorSetLayout(m_p_vulkan_context->_device,
            &post_process_global_layout_create_info,
            NULL,
            &_descriptor_infos[0].layout))
        {
            throw std::runtime_error("create post process global layout");
        }
    }

    void PStencilOutlinePass::setupPipelines()
    { }

    void PStencilOutlinePass::setupDescriptorSet()
    { }

    void PStencilOutlinePass::updateAfterFramebufferRecreate(VkImageView input_attachment)
    { }

    void PStencilOutlinePass::draw()
    { }
}