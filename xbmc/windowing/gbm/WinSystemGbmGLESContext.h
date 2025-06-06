/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "WinSystemGbmEGLContext.h"
#include "rendering/gles/RenderSystemGLES.h"
#include "utils/EGLUtils.h"

#include <memory>

class CVaapiProxy;

namespace KODI
{
namespace WINDOWING
{
namespace GBM
{

class CWinSystemGbmGLESContext : public CWinSystemGbmEGLContext, public CRenderSystemGLES
{
public:
  CWinSystemGbmGLESContext();
  ~CWinSystemGbmGLESContext() override = default;

  static void Register();
  static std::unique_ptr<CWinSystemBase> CreateWinSystem();

  // Implementation of CWinSystemBase via CWinSystemGbm
  CRenderSystemBase* GetRenderSystem() override { return this; }
  bool InitWindowSystem() override;
  bool SetFullScreen(bool fullScreen, RESOLUTION_INFO& res, bool blankOtherDisplays) override;
  void PresentRender(bool rendered, bool videoLayer) override;

protected:
  void SetVSyncImpl(bool enable) override {}
  void PresentRenderImpl(bool rendered) override {};
  bool CreateContext() override;
};

} // namespace GBM
} // namespace WINDOWING
} // namespace KODI
