#include "runtime/function/render/include/render/vulkan_manager/vulkan_common.h"
#include "runtime/function/render/include/render/vulkan_manager/vulkan_mesh.h"
#include "runtime/function/render/include/render/vulkan_manager/vulkan_misc.h"
#include "runtime/function/render/include/render/vulkan_manager/vulkan_passes.h"
#include "runtime/function/render/include/render/vulkan_manager/vulkan_util.h"

#include <stencil_solid_frag.h>

namespace Pilot {

    void PStencilOutlinePass::initialize(VkRenderPass render_pass, VkImageView input_attachment)
    { }

    void PStencilOutlinePass::setupDescriptorSetLayout()
    { }

    void PStencilOutlinePass::setupPipelines()
    { }

    void PStencilOutlinePass::setupDescriptorSet()
    { }

    void PStencilOutlinePass::updateAfterFramebufferRecreate(VkImageView input_attachment)
    { }

    void PStencilOutlinePass::draw()
    { }
}