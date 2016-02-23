/*
  Copyright 1999-2012 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.

  You may not use this file except in compliance with the License.
  obtain a copy of the License at

    http://www.imagemagick.org/script/license.php

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  MagickWand image Methods.
*/

#ifndef _MAGICKWAND_MAGICK_IMAGE_H
#define _MAGICKWAND_MAGICK_IMAGE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

    /*!
     *  @author luojun yan, 2016-02-18 13:02:30
     *
     *  @brief 返回每个通道的图像在四个方向（水平、垂直功能，左、右对角线）为指定的距离。这些特征包括角二阶矩、对比度、相关性、平方和：方差、逆差矩，平均数，和方差，和熵，熵，熵的差异，差异，1的相关信息的措施，2的相关信息的措施，和最大相关系数
     *
     *  @param MagickWand 魔法棒
     *  @param size_t     1
     *
     *  @return 通道信息
     */
extern WandExport ChannelFeatures
  *MagickGetImageChannelFeatures(MagickWand *,const size_t);

    /*!
     *  @author luojun yan, 2016-02-18 13:02:43
     *
     *  @brief 返回图像中每个通道的统计数据。统计包括航道水深，其最小值和最大值，平均值，标准偏差，峰度和偏度
     *
     *  @param MagickWand MagickWand description
     *
     *  @return 通道统计数据
     */
extern WandExport ChannelStatistics
  *MagickGetImageChannelStatistics(MagickWand *);

extern WandExport char
    /*!
     *  @author luojun yan, 2016-02-18 14:02:06
     *
     *  @brief 获取wand中的图像的名称，一般为图像路径
     *
     *  @param MagickWand 魔法棒
     *
     *  @return 文件路径
     */
  *MagickGetImageFilename(MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 14:02:46
     *
     *  @brief 获取wand中的图像格式，例如PNG，JPG等
     *
     *  @param MagickWand 魔法棒
     *
     *  @return 图像格式
     */
  *MagickGetImageFormat(MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 14:02:56
     *
     *  @brief 生成图像的SHA-256 信息摘要 例如：c7e7c0d20b2748666817a40f11e6bd6e97f6b17fb5ebc6e761fd087bc2121f8d
     *
     *  @param MagickWand wand
     *
     *  @return 秘钥字符串
     */
  *MagickGetImageSignature(MagickWand *),
    
    /*!
     *  @author luojun yan, 2016-02-18 14:02:35
     *
     *  @brief 图像的详细信息，包括图像尺寸，大小，像素点数量，颜色空间，通道信息，颜色分布直方图，图片创建时间，修改时间，像素数量等
     *
     *  @param MagickWand wand
     *
     *  @return 详细信息
     */
    *MagickIdentifyImage(MagickWand *);

    /*!
     *  @author luojun yan, 2016-02-18 14:02:14
     *
     *  @brief 获取颜色空间
     *
     *  @param MagickWand wand
     *
     *  @return 颜色空间
     */
extern WandExport ColorspaceType
    MagickGetImageColorspace(MagickWand *);

    /*!
     *  @author luojun yan, 2016-02-18 14:02:23
     *
     *  @brief
     *
     *  @param MagickWand
     *
     *  @return
     */
extern WandExport CompositeOperator
  MagickGetImageCompose(MagickWand *);

    /*!
     *  @author luojun yan, 2016-02-18 14:02:33
     *
     *  @brief 获取图像的压缩类型
     *
     *  @param MagickWand wand
     *
     *  @return 压缩类型 例如jpg、zip等等
     */
extern WandExport CompressionType
  MagickGetImageCompression(MagickWand *);

    /*!
     *  @author luojun yan, 2016-02-18 14:02:54
     *
     *  @brief 获取图片被处理方法
     *
     *  @param MagickWand
     *
     *  @return 处理方法
     */
extern WandExport DisposeType
  MagickGetImageDispose(MagickWand *);

extern WandExport double
    /*!
     *  @author luojun yan, 2016-02-18 14:02:48
     *
     *  @brief 重绘图像，并返回重绘导致的失真度
     *
     *  @param MagickWand 新图wand
     *  @param MagickWand 旧图wand
     *  @param MetricType 失真度
     *
     *  @return 是否成功
     */
  *MagickGetImageChannelDistortions(MagickWand *,const MagickWand *,
    const MetricType),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:38
     *
     *  @brief 获取图像模糊度
     *
     *  @param MagickWand wand
     *
     *  @return 模糊度
     */
  MagickGetImageFuzz(MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:45
     *
     *  @brief 获取图像的伽马校正值
     *
     *  @param MagickWand wand
     *
     *  @return 校正值
     */
  MagickGetImageGamma(MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:40
     *
     *  @brief 获取图像的全墨密度
     *
     *  @param MagickWand wand
     *
     *  @return 密度值
     */
    MagickGetImageTotalInkDensity(MagickWand *);

    /*!
     *  @author luojun yan, 2016-02-18 15:02:07
     *
     *  @brief 图像重力类型
     *
     *  @param MagickWand wand
     *
     *  @return 重力类型
     */
extern WandExport GravityType
  MagickGetImageGravity(MagickWand *);

extern WandExport Image
    /*!
     *  @author luojun yan, 2016-02-18 15:02:14
     *
     *  @brief 释放与该图像相关的内存
     *
     *  @param Image 目标图像
     *
     *  @return 释放内存之后的图像
     */
  *MagickDestroyImage(Image *),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:45
     *
     *  @brief 从wand中获取图像
     *
     *  @param MagickWand wand
     *
     *  @return 图像
     */
    *GetImageFromMagickWand(const MagickWand *);
    
    /*!
     *  @author luojun yan, 2016-02-18 15:02:59
     *
     *  @brief 获取可能的图像类型,MagickSetImageType 设置图像类型
     *
     *  @param MagickWand wand
     *
     *  @return 图像类型
     */
extern WandExport ImageType
  MagickGetImageType(MagickWand *);

    /*!
     *  @author luojun yan, 2016-02-18 15:02:59
     *
     *  @brief 获取图像交织方案
     *
     *  @param MagickWand wand
     *
     *  @return 交织方案 如：jpg，png，gif等
     */
extern WandExport InterlaceType
  MagickGetImageInterlaceScheme(MagickWand *);
    /*!
     *  @author luojun yan, 2016-02-18 15:02:39
     *
     *  @brief 获取图像交织方法
     *
     *  @param MagickWand wand
     *
     *  @return 方法
     */
extern WandExport InterpolatePixelMethod
  MagickGetImageInterpolateMethod(MagickWand *);

extern WandExport MagickBooleanType
    /*!
     *  @author luojun yan, 2016-02-18 15:02:58
     *
     *  @brief 自适应模糊化图像
     *
     *  @param MagickWand wand
     *  @param double     模糊半径
     *  @param double     西伽马高斯算法偏差值
     *
     *  @return 成功失败
     */
  MagickAdaptiveBlurImage(MagickWand *,const double,const double),
  MagickAdaptiveBlurImageChannel(MagickWand *,const ChannelType,const double,
    const double),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:58
     *
     *  @brief 根据行和列重绘图像
     *
     *  @param MagickWand wand
     *  @param size_t     列数
     *  @param size_t     行数
     *
     *  @return 是否成功
     */
  MagickAdaptiveResizeImage(MagickWand *,const size_t,const size_t),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:00
     *
     *  @brief 自动锐化图像
     *
     *  @param MagickWand wamd
     *  @param double     模糊半径
     *  @param double     西伽马高斯算法偏差值
     *
     *  @return 是否成功
     */
  MagickAdaptiveSharpenImage(MagickWand *,const double,const double),
  MagickAdaptiveSharpenImageChannel(MagickWand *,const ChannelType,const double,
    const double),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:21
     *
     *  @brief 自适应每个像素的阀值
     *
     *  @param MagickWand wand
     *  @param size_t     宽度
     *  @param size_t     高度
     *  @param ssize_t    偏移量
     *
     *  @return 成功标记
     */
  MagickAdaptiveThresholdImage(MagickWand *,const size_t,const size_t,
    const ssize_t),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:27
     *
     *  @brief 把后面一个图像的wand添加到前面的图像wand
     *
     *  @param MagickWand 结果wand
     *  @param MagickWand 目标wand
     *
     *  @return 是否成功
     */
  MagickAddImage(MagickWand *,const MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:20
     *
     *  @brief 给图像随机添加噪点
     *
     *  @param MagickWand wand
     *  @param NoiseType  噪点类型
     *
     *  @return 是否成功
     */
  MagickAddNoiseImage(MagickWand *,const NoiseType),
  MagickAddNoiseImageChannel(MagickWand *,const ChannelType,const NoiseType),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:04
     *
     *  @brief 通过放射矩阵来变换图像
     *
     *  @param MagickWand  目标wand
     *  @param DrawingWand 放射矩阵
     *
     *  @return 是否成功
     */
  MagickAffineTransformImage(MagickWand *,const DrawingWand *),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:00
     *
     *  @brief 给图片添加文字注释
     *
     *  @param MagickWand  wand
     *  @param DrawingWand wand
     *  @param double      x坐标
     *  @param double      y坐标
     *  @param double      锚点
     *  @param char        注释文本
     *
     *  @return 是否成功
     */
  MagickAnnotateImage(MagickWand *,const DrawingWand *,const double,
    const double,const double,const char *),
  MagickAnimateImages(MagickWand *,const char *),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:32
     *
     *  @brief
     *
     *  @param MagickWand
     *
     *  @return
     */
  MagickAutoGammaImage(MagickWand *),
  MagickAutoGammaImageChannel(MagickWand *,const ChannelType),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:42
     *
     *  @brief 自动调节通道水平
     *
     *  @param MagickWand wand
     *
     *  @return 是否成功
     */
  MagickAutoLevelImage(MagickWand *),
  MagickAutoLevelImageChannel(MagickWand *,const ChannelType),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:04
     *
     *  @brief 将阀值范围内的所有像素点变为黑色
     *
     *  @param MagickWand wand
     *  @param PixelWand  pixelwand
     *
     *  @return 成功标记
     */
  MagickBlackThresholdImage(MagickWand *,const PixelWand *),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:19
     *
     *  @brief 弱化颜色来模拟一个夜间场景
     *
     *  @param MagickWand wand
     *  @param double     弱化参数 默认1.5
     *
     *  @return 是否成功
     */
  MagickBlueShiftImage(MagickWand *,const double),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:40
     *
     *  @brief 模糊化图像
     *
     *  @param MagickWand wand
     *  @param double     作用半径
     *  @param double     伽马偏移参数
     *
     *  @return <#return value description#>
     */
  MagickBlurImage(MagickWand *,const double,const double),
  MagickBlurImageChannel(MagickWand *,const ChannelType,const double,
    const double),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:36
     *
     *  @brief 给图像添加边框
     *
     *  @param MagickWand wand
     *  @param PixelWand  边框颜色
     *  @param size_t     边框宽度
     *  @param size_t     边框高度
     *
     *  @return 是否成功
     */
  MagickBorderImage(MagickWand *,const PixelWand *,const size_t,const size_t),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:06
     *
     *  @brief 改变图像的亮度和对比度
     *
     *  @param MagickWand wand
     *  @param double     亮度
     *  @param double     对比度
     *
     *  @return 是否成功
     */
  MagickBrightnessContrastImage(MagickWand *,const double,const double),
  MagickBrightnessContrastImageChannel(MagickWand *,const ChannelType,
    const double,const double),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:29
     *
     *  @brief 模拟木炭画
     *
     *  @param MagickWand wand
     *  @param double     半径
     *  @param double     伽马参数
     *
     *  @return 是否成功
     */
  MagickCharcoalImage(MagickWand *,const double,const double),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:29
     *
     *  @brief 抠图
     *
     *  @param MagickWand wand
     *  @param size_t     抠图区域宽度
     *  @param size_t     抠图区域高度
     *  @param ssize_t    抠图x坐标
     *  @param ssize_t    抠图y坐标
     *
     *  @return 是否成功
     */
  MagickChopImage(MagickWand *,const size_t,const size_t,const ssize_t,
    const ssize_t),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:03
     *
     *  @brief 钳图
     *
     *  @param MagickWand wand
     *
     *  @return 是否成功
     */
  MagickClampImage(MagickWand *),
  MagickClampImageChannel(MagickWand *,const ChannelType),
    /*!
     *  @author luojun yan, 2016-02-18 15:02:08
     *
     *  @brief 图片裁剪
     *
     *  @param MagickWand wand
     *
     *  @return 裁剪是否成功
     */
  MagickClipImage(MagickWand *),
  MagickClipImagePath(MagickWand *,const char *,const MagickBooleanType),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:07
     *
     *  @brief 颜色替换
     *
     *  @param MagickWand 结果wand
     *  @param MagickWand 目标wand
     *
     *  @return 替换是否成功
     */
  MagickClutImage(MagickWand *,const MagickWand *),
  MagickClutImageChannel(MagickWand *,const ChannelType,const MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:23
     *
     *  @brief  设置颜色决策表
     *
     *  @param MagickWand wand
     *  @param char       决策表路径
     *
     *  @return 是否成功
     */
  MagickColorDecisionListImage(MagickWand *,const char *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:38
     *
     *  @brief 混合颜色到已有wand
     *
     *  @param MagickWand 结果wand
     *  @param PixelWand  颜色
     *  @param PixelWand  透明度
     *
     *  @return 是否成功
     */
  MagickColorizeImage(MagickWand *,const PixelWand *,const PixelWand *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:30
     *
     *  @brief 根据矩阵参数来调整图像
     *
     *  @param MagickWand wand
     *  @param KernelInfo 矩阵参数文件
     *
     *  @return 是否成功
     */
  MagickColorMatrixImage(MagickWand *,const KernelInfo *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:32
     *
     *  @brief 给图像添加评论
     *
     *  @param MagickWand wand
     *  @param char       评论内容
     *
     *  @return 是否成功
     */
  MagickCommentImage(MagickWand *,const char *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:31
     *
     *  @brief 合并两幅图片
     *
     *  @param MagickWand        结果wand
     *  @param MagickWand        目标wand
     *  @param CompositeOperator 合成器
     *  @param ssize_t           x坐标
     *  @param ssize_t           y坐标
     *
     *  @return 是否成功
     */
  MagickCompositeImage(MagickWand *,const MagickWand *,const CompositeOperator,
    const ssize_t,const ssize_t),
  MagickCompositeImageChannel(MagickWand *,const ChannelType,const MagickWand *,    const CompositeOperator,const ssize_t,const ssize_t),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:26
     *
     *  @brief 把像素数据填充到图像
     *
     *  @param MagickWand  wand
     *  @param size_t      列数
     *  @param size_t      行数
     *  @param char        map
     *  @param StorageType storage
     *  @param void        像素数据
     *
     *  @return 是否成功
     */
  MagickConstituteImage(MagickWand *,const size_t,const size_t,const char *,
    const StorageType,const void *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:39
     *
     *  @brief 调整图像对比度
     *
     *  @param MagickWand        wand
     *  @param MagickBooleanType 是否锐化
     *
     *  @return 是否成功
     */
  MagickContrastImage(MagickWand *,const MagickBooleanType),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:48
     *
     *  @brief 通过调整黑色和白色来改变对比度
     *
     *  @param MagickWand wand
     *  @param double     黑色
     *  @param double     白色
     *
     *  @return 是否成功
     */
  MagickContrastStretchImage(MagickWand *,const double,const double),
  MagickContrastStretchImageChannel(MagickWand *,const ChannelType,const double,
    const double),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:20
     *
     *  @brief 卷积图像
     *
     *  @param MagickWand wand
     *  @param size_t     顺序
     *  @param double     自定卷积核文件路径
     *
     *  @return 是否成功
     */
  MagickConvolveImage(MagickWand *,const size_t,const double *),
  MagickConvolveImageChannel(MagickWand *,const ChannelType,const size_t,
    const double *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:50
     *
     *  @brief 提取图像
     *
     *  @param MagickWand wand
     *  @param size_t     宽
     *  @param size_t     高
     *  @param ssize_t    x
     *  @param ssize_t    y
     *
     *  @return 是否成功
     */
  MagickCropImage(MagickWand *,const size_t,const size_t,const ssize_t,
    const ssize_t),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:46
     *
     *  @brief 图像映射
     *
     *  @param MagickWand wand
     *  @param ssize_t 要影响的像素点数量
     *
     *  @return 是否成功
     */
  MagickCycleColormapImage(MagickWand *,const ssize_t),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:40
     *
     *  @brief 解密像素，将密码像素解密为纯像素
     *
     *  @param MagickWand wand
     *  @param char       密码
     *
     *  @return 是否成功
     */
  MagickDecipherImage(MagickWand *,const char *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:21
     *
     *  @brief 图像矫正
     *
     *  @param MagickWand wand
     *  @param double     阀值
     *
     *  @return 是否成功
     */
  MagickDeskewImage(MagickWand *,const double),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:13
     *
     *  @brief 减少图像斑点，噪点，同时保持图像边界
     *
     *  @param MagickWand wand
     *
     *  @return 是否成功
     */
  MagickDespeckleImage(MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:19
     *
     *  @brief 显示网络图片
     *
     *  @param MagickWand wand
     *  @param char       图片url
     *
     *  @return 是否成功
     */
  MagickDisplayImage(MagickWand *,const char *),
  MagickDisplayImages(MagickWand *,const char *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:40
     *
     *  @brief 扭曲图像
     *
     *  @param MagickWand         wand
     *  @param DistortImageMethod 扭曲方法
     *  @param size_t             参数数量
     *  @param double             参数内容
     *  @param MagickBooleanType  是否适应新图像
     *
     *  @return 是否成功
     */
  MagickDistortImage(MagickWand *,const DistortImageMethod,const size_t,
    const double *,const MagickBooleanType),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:27
     *
     *  @brief 把draw wand 应用到当前wand中
     *
     *  @param MagickWand  wand
     *  @param DrawingWand draw wand
     *
     *  @return 是否成功
     */
  MagickDrawImage(MagickWand *,const DrawingWand *),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:29
     *
     *  @brief 刻画图像的线条
     *
     *  @param MagickWand wand
     *  @param double     线条粗细
     *
     *  @return 是否成功
     */
  MagickEdgeImage(MagickWand *,const double),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:50
     *
     *  @brief 增加图片的立体感（浮雕化）
     *
     *  @param MagickWand wand
     *  @param double     半径 一般0-10 不会很大
     *  @param double     伽马偏移量 默认1.5
     *
     *  @return 是否成功
     */
  MagickEmbossImage(MagickWand *,const double,const double),
    /*!
     *  @author luojun yan, 2016-02-18 16:02:32
     *
     *  @brief 加密图片 亲测可用。
     *
     *  @param MagickWand wand
     *  @param char       密码
     *
     *  @return 是否成功
     */
  MagickEncipherImage(MagickWand *,const char *),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:32
     *
     *  @brief 适用于数字滤波器，以提高降噪质量
     *
     *  @param MagickWand wand
     *
     *  @return 是否成功
     */
  MagickEnhanceImage(MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:54
     *
     *  @brief 对图像作直方图均衡
     *
     *  @param MagickWand wand
     *
     *  @return 是否成功
     */
  MagickEqualizeImage(MagickWand *),
  MagickEqualizeImageChannel(MagickWand *,const ChannelType),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:02
     *
     *  @brief 调整图像，使图像变暗，亮，或者对比度变化，根据逻辑算式和表达式等
     *
     *  @param MagickWand             wand
     *  @param MagickEvaluateOperator 操作器
     *  @param double                 值
     *
     *  @return 是否成功
     */
  MagickEvaluateImage(MagickWand *,const MagickEvaluateOperator,const double),
  MagickEvaluateImageChannel(MagickWand *,const ChannelType,
    const MagickEvaluateOperator,const double),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:21
     *
     *  @brief 提取像素 例如：MagickExportImagePixels(wand,0,0,640,1,"RGB",CharPixel,pixels);
     *
     *  @param MagickWand  wand
     *  @param ssize_t     x
     *  @param ssize_t     y
     *  @param size_t      列数
     *  @param size_t      行数
     *  @param char        map
     *  @param StorageType storageType
     *  @param void *      保存提取的像素
     *
     *  @return 是否成功
     */
  MagickExportImagePixels(MagickWand *,const ssize_t,const ssize_t,
    const size_t,const size_t,const char *,const StorageType,void *),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:42
     *
     *  @brief 扩展原来wand的重力，宽，高等属性，从而达到扩展图像的目的
     *
     *  @param MagickWand wand
     *  @param size_t     宽
     *  @param size_t     高
     *  @param ssize_t    x
     *  @param ssize_t    y
     *
     *  @return 是否成功
     */
  MagickExtentImage(MagickWand *,const size_t,const size_t,const ssize_t,
    const ssize_t),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:04
     *
     *  @brief 把自定义卷积应用到图像上
     *
     *  @param MagickWand wand
     *  @param KernelInfo 卷积
     *
     *  @return 是否成功
     */
  MagickFilterImage(MagickWand *,const KernelInfo *),
  MagickFilterImageChannel(MagickWand *,const ChannelType,const KernelInfo *),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:26
     *
     *  @brief 把图像垂直反转
     *
     *  @param MagickWand wand
     *
     *  @return 是否成功
     */
  MagickFlipImage(MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:28
     *
     *  @brief 强力填充颜色
     *
     *  @param MagickWand        wand
     *  @param ChannelType       通道信息
     *  @param PixelWand         填充颜色
     *  @param double            By default target must match a particular pixel color exactly. However, in many cases two colors may differ by a small amount. The fuzz member of image defines how much tolerance is acceptable to consider two colors as the same. For example, set fuzz to 10 and the color red at intensities of 100 and 102 respectively are now interpreted as the same color for the purposes of the floodfill.
     *  @param PixelWand         填充宽度
     *  @param ssize_t           x
     *  @param ssize_t           y
     *  @param MagickBooleanType paint any pixel that does not match the target color.
     *
     *  @return 是否成功
     */
  MagickFloodfillPaintImage(MagickWand *,const ChannelType,const PixelWand *,
    const double,const PixelWand *,const ssize_t,const ssize_t,
    const MagickBooleanType),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:02
     *
     *  @brief 把图片水平反转
     *
     *  @param MagickWand wand
     *
     *  @return 是否成功
     */
  MagickFlopImage(MagickWand *),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:27
     *
     *  @brief 离散里叶变换（DFT）
     *
     *  @param MagickWand        wand
     *  @param MagickBooleanType if true, return as magnitude / phase pair otherwise a real / imaginary image pair.
     *
     *  @return 是否成功
     */
  MagickForwardFourierTransformImage(MagickWand *,const MagickBooleanType),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:17
     *
     *  @brief 增加三维边界
     *
     *  @param MagickWand wand
     *  @param PixelWand  边界颜色
     *  @param size_t     边界宽
     *  @param size_t     边界高
     *  @param ssize_t    内锥宽度
     *  @param ssize_t    外锥宽度
     *
     *  @return 是否成功
     */
  MagickFrameImage(MagickWand *,const PixelWand *,const size_t,const size_t,
    const ssize_t,const ssize_t),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:58
     *
     *  @brief  an arithmetic, relational, or logical expression to an image. Use these operators to lighten or darken an image, to increase or decrease contrast in an image, or to produce the "negative" of an image.
     *
     *  @param MagickWand     wand
     *  @param MagickFunction image function
     *  @param size_t         参数数量
     *  @param double         参数内容
     *
     *  @return 是否成功
     */
  MagickFunctionImage(MagickWand *,const MagickFunction,const size_t,
    const double *),
  MagickFunctionImageChannel(MagickWand *,const ChannelType,
    const MagickFunction,const size_t,const double *),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:01
     *
     *  @brief 伽马矫正图像
     *
     *  @param MagickWand wand
     *  @param double     伽马值 0.8-2.3
     *
     *  @return 是否成功
     */
  MagickGammaImage(MagickWand *,const double),
  MagickGammaImageChannel(MagickWand *,const ChannelType,const double),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:58
     *
     *  @brief 高斯模糊图像
     *
     *  @param MagickWand wand
     *  @param double     模糊半径
     *  @param double     伽马参数
     *
     *  @return 是否成功
     */
  MagickGaussianBlurImage(MagickWand *,const double,const double),
  MagickGaussianBlurImageChannel(MagickWand *,const ChannelType,const double,
    const double),
    /*!
     *  @author luojun yan, 2016-02-18 17:02:38
     *
     *  @brief 判断图像是否含alpa
     *
     *  @param MagickWand wand
     *
     *  @return 返回yes 代表包含alpa
     */
  MagickGetImageAlphaChannel(MagickWand *),
  MagickGetImageBackgroundColor(MagickWand *,PixelWand *),
  MagickGetImageBluePrimary(MagickWand *,double *,double *),
  MagickGetImageBorderColor(MagickWand *,PixelWand *),
  MagickGetImageChannelDistortion(MagickWand *,const MagickWand *,
    const ChannelType,const MetricType,double *),
  MagickGetImageChannelKurtosis(MagickWand *,const ChannelType,double *,
    double *),
  MagickGetImageChannelMean(MagickWand *,const ChannelType,double *,double *),
  MagickGetImageChannelRange(MagickWand *,const ChannelType,double *,double *),
  MagickGetImageColormapColor(MagickWand *,const size_t,PixelWand *),
  MagickGetImageDistortion(MagickWand *,const MagickWand *,const MetricType,
    double *),
  MagickGetImageGreenPrimary(MagickWand *,double *,double *),
  MagickGetImageMatteColor(MagickWand *,PixelWand *),
  MagickGetImageLength(MagickWand *,MagickSizeType *),
  MagickGetImagePage(MagickWand *,size_t *,size_t *,ssize_t *,
    ssize_t *),
  MagickGetImagePixelColor(MagickWand *,const ssize_t,const ssize_t,
    PixelWand *),
  MagickGetImageRange(MagickWand *,double *,double *),
  MagickGetImageRedPrimary(MagickWand *,double *,double *),
  MagickGetImageResolution(MagickWand *,double *,double *),
  MagickGetImageWhitePoint(MagickWand *,double *,double *),
  MagickHaldClutImage(MagickWand *,const MagickWand *),
  MagickHaldClutImageChannel(MagickWand *,const ChannelType,const MagickWand *),
  MagickHasNextImage(MagickWand *),
  MagickHasPreviousImage(MagickWand *),
  MagickImplodeImage(MagickWand *,const double),
  MagickImportImagePixels(MagickWand *,const ssize_t,const ssize_t,const size_t,
    const size_t,const char *,const StorageType,const void *),
  MagickInverseFourierTransformImage(MagickWand *,MagickWand *,
    const MagickBooleanType),
  MagickLabelImage(MagickWand *,const char *),
  MagickLevelImage(MagickWand *,const double,const double,const double),
  MagickLevelImageChannel(MagickWand *,const ChannelType,const double,
    const double,const double),
  MagickLinearStretchImage(MagickWand *,const double,const double),
  MagickLiquidRescaleImage(MagickWand *,const size_t,const size_t,const double,
    const double),
  MagickMagnifyImage(MagickWand *),
  MagickMedianFilterImage(MagickWand *,const double),
  MagickMinifyImage(MagickWand *),
  MagickModeImage(MagickWand *,const double),
  MagickModulateImage(MagickWand *,const double,const double,const double),
  MagickMorphologyImage(MagickWand *,MorphologyMethod,const ssize_t,
    KernelInfo *),
  MagickMorphologyImageChannel(MagickWand *,const ChannelType,MorphologyMethod,
    const ssize_t,KernelInfo *),
  MagickMotionBlurImage(MagickWand *,const double,const double,const double),
  MagickMotionBlurImageChannel(MagickWand *,const ChannelType,const double,
    const double,const double),
  MagickNegateImage(MagickWand *,const MagickBooleanType),
  MagickNegateImageChannel(MagickWand *,const ChannelType,
    const MagickBooleanType),
  MagickNewImage(MagickWand *,const size_t,const size_t,const PixelWand *),
  MagickNextImage(MagickWand *),
  MagickNormalizeImage(MagickWand *),
  MagickNormalizeImageChannel(MagickWand *,const ChannelType),
  MagickOilPaintImage(MagickWand *,const double),
  MagickOpaquePaintImage(MagickWand *,const PixelWand *,const PixelWand *,
    const double,const MagickBooleanType),
  MagickOpaquePaintImageChannel(MagickWand *,const ChannelType,
    const PixelWand *,const PixelWand *,const double,const MagickBooleanType),
  MagickOrderedPosterizeImage(MagickWand *,const char *),
  MagickOrderedPosterizeImageChannel(MagickWand *,const ChannelType,
    const char *),
  MagickTransparentPaintImage(MagickWand *,const PixelWand *,
    const double,const double,const MagickBooleanType invert),
  MagickPingImage(MagickWand *,const char *),
  MagickPingImageBlob(MagickWand *,const void *,const size_t),
  MagickPingImageFile(MagickWand *,FILE *),
  MagickPolaroidImage(MagickWand *,const DrawingWand *,const double),
  MagickPosterizeImage(MagickWand *,const size_t,const MagickBooleanType),
  MagickPreviousImage(MagickWand *),
    
    /*!
     *  @author luojun yan, 2016-02-18 13:02:18
     *
     *  @brief 量化图像  （就是把彩色变成黑白)MagickQuantizeImage(self.wand,2,GRAYColorspace,1,MagickFalse,MagickFalse);
     *
     *  @param MagickWand        魔棒实例
     *  @param size_t            目标颜色数量 Target number colors
     *  @param ColorspaceType    颜色空间
     *  @param size_t            最佳深度 Optimal depth
     *  @param MagickBooleanType 无抖动 No-dither
     *  @param MagickBooleanType 量化误差 Quantization error
     *
     *  @return
     */
  MagickQuantizeImage(MagickWand *,const size_t,const ColorspaceType,
    const size_t,const MagickBooleanType,const MagickBooleanType),
  MagickQuantizeImages(MagickWand *,const size_t,const ColorspaceType,
    const size_t,const MagickBooleanType,const MagickBooleanType),
    
  MagickRadialBlurImage(MagickWand *,const double),
  MagickRadialBlurImageChannel(MagickWand *,const ChannelType,const double),
  MagickRaiseImage(MagickWand *,const size_t,const size_t,const ssize_t,
    const ssize_t,const MagickBooleanType),
  MagickRandomThresholdImage(MagickWand *,const double,const double),
  MagickRandomThresholdImageChannel(MagickWand *,const ChannelType,const double,
    const double),
  MagickReadImage(MagickWand *,const char *),
  MagickReadImageBlob(MagickWand *,const void *,const size_t),
  MagickReadImageFile(MagickWand *,FILE *),
  MagickReduceNoiseImage(MagickWand *,const double),
  MagickRemapImage(MagickWand *,const MagickWand *,const DitherMethod),
  MagickRemoveImage(MagickWand *),
  MagickResampleImage(MagickWand *,const double,const double,const FilterTypes,
    const double),
  MagickResetImagePage(MagickWand *,const char *),
  MagickResizeImage(MagickWand *,const size_t,const size_t,const FilterTypes,
    const double),
  MagickRollImage(MagickWand *,const ssize_t,const ssize_t),
  MagickRotateImage(MagickWand *,const PixelWand *,const double),
  MagickSampleImage(MagickWand *,const size_t,const size_t),
  MagickScaleImage(MagickWand *,const size_t,const size_t),
  MagickSegmentImage(MagickWand *,const ColorspaceType,const MagickBooleanType,
    const double,const double),
  MagickSelectiveBlurImage(MagickWand *,const double,const double,const double),
  MagickSelectiveBlurImageChannel(MagickWand *,const ChannelType,const double,
    const double,const double),
  MagickSeparateImageChannel(MagickWand *,const ChannelType),
  MagickSepiaToneImage(MagickWand *,const double),
  MagickSetImage(MagickWand *,const MagickWand *),
  MagickSetImageAlphaChannel(MagickWand *,const AlphaChannelType),
  MagickSetImageBackgroundColor(MagickWand *,const PixelWand *),
  MagickSetImageBias(MagickWand *,const double),
  MagickSetImageBluePrimary(MagickWand *,const double,const double),
  MagickSetImageBorderColor(MagickWand *,const PixelWand *),
  MagickSetImageChannelDepth(MagickWand *,const ChannelType,const size_t),
  MagickSetImageClipMask(MagickWand *,const MagickWand *),
  MagickSetImageColor(MagickWand *,const PixelWand *),
  MagickSetImageColormapColor(MagickWand *,const size_t,
    const PixelWand *),
  MagickSetImageColorspace(MagickWand *,const ColorspaceType),
  MagickSetImageCompose(MagickWand *,const CompositeOperator),
  MagickSetImageCompression(MagickWand *,const CompressionType),
  MagickSetImageDelay(MagickWand *,const size_t),
  MagickSetImageDepth(MagickWand *,const size_t),
  MagickSetImageDispose(MagickWand *,const DisposeType),
  MagickSetImageCompressionQuality(MagickWand *,const size_t),
  MagickSetImageExtent(MagickWand *,const size_t,const size_t),
  MagickSetImageFilename(MagickWand *,const char *),
  MagickSetImageFormat(MagickWand *,const char *),
  MagickSetImageFuzz(MagickWand *,const double),
  MagickSetImageGamma(MagickWand *,const double),
  MagickSetImageGravity(MagickWand *,const GravityType),
  MagickSetImageGreenPrimary(MagickWand *,const double,const double),
  MagickSetImageInterlaceScheme(MagickWand *,const InterlaceType),
  MagickSetImageInterpolateMethod(MagickWand *,const InterpolatePixelMethod),
  MagickSetImageIterations(MagickWand *,const size_t),
  MagickSetImageMatte(MagickWand *,const MagickBooleanType),
  MagickSetImageMatteColor(MagickWand *,const PixelWand *),
  MagickSetImageOpacity(MagickWand *,const double),
  MagickSetImageOrientation(MagickWand *,const OrientationType),
  MagickSetImagePage(MagickWand *,const size_t,const size_t,const ssize_t,
    const ssize_t),
  MagickSetImageRedPrimary(MagickWand *,const double,const double),
  MagickSetImageRenderingIntent(MagickWand *,const RenderingIntent),
  MagickSetImageResolution(MagickWand *,const double,const double),
  MagickSetImageScene(MagickWand *,const size_t),
  MagickSetImageTicksPerSecond(MagickWand *,const ssize_t),
  MagickSetImageType(MagickWand *,const ImageType),
  MagickSetImageUnits(MagickWand *,const ResolutionType),
  MagickSetImageWhitePoint(MagickWand *,const double,const double),
  MagickShadeImage(MagickWand *,const MagickBooleanType,const double,
    const double),
  MagickShadowImage(MagickWand *,const double,const double,const ssize_t,
    const ssize_t),
  MagickSharpenImage(MagickWand *,const double,const double),
  MagickSharpenImageChannel(MagickWand *,const ChannelType,const double,
    const double),
  MagickShaveImage(MagickWand *,const size_t,const size_t),
  MagickShearImage(MagickWand *,const PixelWand *,const double,const double),
  MagickSigmoidalContrastImage(MagickWand *,const MagickBooleanType,
    const double,const double),
  MagickSigmoidalContrastImageChannel(MagickWand *,const ChannelType,
    const MagickBooleanType,const double,const double),
  MagickSketchImage(MagickWand *,const double,const double,const double),
  MagickSolarizeImage(MagickWand *,const double),
  MagickSparseColorImage(MagickWand *,const ChannelType,const SparseColorMethod,
    const size_t,const double *),
  MagickSpliceImage(MagickWand *,const size_t,const size_t,const ssize_t,
    const ssize_t),
  MagickSpreadImage(MagickWand *,const double),
  MagickStatisticImage(MagickWand *,const ChannelType,const StatisticType,
    const size_t,const size_t),
  MagickStatisticImageChannel(MagickWand *,const StatisticType,const size_t,
    const size_t),
  MagickStripImage(MagickWand *),
  MagickSwirlImage(MagickWand *,const double),
  MagickTintImage(MagickWand *,const PixelWand *,const PixelWand *),
  MagickTransformImageColorspace(MagickWand *,const ColorspaceType),
  MagickTransposeImage(MagickWand *),
  MagickTransverseImage(MagickWand *),
  MagickThresholdImage(MagickWand *,const double),
  MagickThresholdImageChannel(MagickWand *,const ChannelType,const double),
  MagickThumbnailImage(MagickWand *,const size_t,const size_t),
  MagickTrimImage(MagickWand *,const double),
  MagickUniqueImageColors(MagickWand *),
  MagickUnsharpMaskImage(MagickWand *,const double,const double,const double,
    const double),
  MagickUnsharpMaskImageChannel(MagickWand *,const ChannelType,const double,
    const double,const double,const double),
  MagickVignetteImage(MagickWand *,const double,const double,const ssize_t,
    const ssize_t),
  MagickWaveImage(MagickWand *,const double,const double),
  MagickWhiteThresholdImage(MagickWand *,const PixelWand *),
  MagickWriteImage(MagickWand *,const char *),
  MagickWriteImageFile(MagickWand *,FILE *),
  MagickWriteImages(MagickWand *,const char *,const MagickBooleanType),
  MagickWriteImagesFile(MagickWand *,FILE *);

WandExport MagickProgressMonitor
  MagickSetImageProgressMonitor(MagickWand *,const MagickProgressMonitor,
    void *);

extern WandExport MagickWand
  *MagickAppendImages(MagickWand *,const MagickBooleanType),
  *MagickCoalesceImages(MagickWand *),
  *MagickCombineImages(MagickWand *,const ChannelType),
  *MagickCompareImageChannels(MagickWand *,const MagickWand *,const ChannelType,
    const MetricType,double *),
  *MagickCompareImages(MagickWand *,const MagickWand *,const MetricType,
    double *),
  *MagickCompareImageLayers(MagickWand *,const ImageLayerMethod),
  *MagickDeconstructImages(MagickWand *),
  *MagickEvaluateImages(MagickWand *,const MagickEvaluateOperator),
  *MagickFxImage(MagickWand *,const char *),
  *MagickFxImageChannel(MagickWand *,const ChannelType,const char *),
  *MagickGetImage(MagickWand *),
  *MagickGetImageClipMask(MagickWand *),
  *MagickGetImageRegion(MagickWand *,const size_t,const size_t,const ssize_t,
    const ssize_t),
  *MagickMergeImageLayers(MagickWand *,const ImageLayerMethod),
  *MagickMorphImages(MagickWand *,const size_t),
  *MagickMontageImage(MagickWand *,const DrawingWand *,const char *,
    const char *,const MontageMode,const char *),
  *MagickOptimizeImageLayers(MagickWand *),
  *MagickPreviewImages(MagickWand *wand,const PreviewType),
  *MagickSimilarityImage(MagickWand *,const MagickWand *,RectangleInfo *,
    double *),
  *MagickSmushImages(MagickWand *,const MagickBooleanType,const ssize_t),
  *MagickSteganoImage(MagickWand *,const MagickWand *,const ssize_t),
  *MagickStereoImage(MagickWand *,const MagickWand *),
  *MagickTextureImage(MagickWand *,const MagickWand *),
  *MagickTransformImage(MagickWand *,const char *,const char *);

extern WandExport OrientationType
  MagickGetImageOrientation(MagickWand *);

extern WandExport PixelWand
  **MagickGetImageHistogram(MagickWand *,size_t *);

extern WandExport RenderingIntent
  MagickGetImageRenderingIntent(MagickWand *);

extern WandExport ResolutionType
  MagickGetImageUnits(MagickWand *);

extern WandExport size_t
  MagickGetImageColors(MagickWand *),
  MagickGetImageCompressionQuality(MagickWand *),
  MagickGetImageDelay(MagickWand *),
  MagickGetImageChannelDepth(MagickWand *,const ChannelType),
  MagickGetImageDepth(MagickWand *),
  MagickGetImageHeight(MagickWand *),
  MagickGetImageIterations(MagickWand *),
  MagickGetImageScene(MagickWand *),
  MagickGetImageTicksPerSecond(MagickWand *),
  MagickGetImageWidth(MagickWand *),
  MagickGetNumberImages(MagickWand *);

extern WandExport unsigned char
  *MagickGetImageBlob(MagickWand *,size_t *),
  *MagickGetImagesBlob(MagickWand *,size_t *);

extern WandExport VirtualPixelMethod
  MagickGetImageVirtualPixelMethod(MagickWand *),
  MagickSetImageVirtualPixelMethod(MagickWand *,const VirtualPixelMethod);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
