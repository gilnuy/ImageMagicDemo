//
//  ViewController.m
//  ImageMagicDemo
//
//  Created by yanluojun on 16/2/23.
//  Copyright © 2016年 yanluojun. All rights reserved.
//

#import "ViewController.h"
#import "MagickWand.h"

@interface ViewController ()
@property (nonatomic) MagickWand *wand;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self createGif];
    
    // Do any additional setup after loading the view, typically from a nib.
}

//合成gif
- (void)createGif {
    //    [self compressToJpg];
    //    return;
    
    NSMutableArray *frames = [[NSMutableArray alloc] init];
    int x = 0;
    UIImage *imagezor = [[UIImage alloc] initWithContentsOfFile:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"old_%d", x] ofType:@"png"]];
    NSLog(@"%@", imagezor);
    while(imagezor != NULL) {
        [frames addObject:imagezor];
        x++;
        imagezor = [[UIImage alloc] initWithContentsOfFile:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"old_%d", x] ofType:@"png"]];
        NSLog(@"%@", imagezor);
    }
    MagickWand *mw = NewMagickWand();
    MagickSetFormat(mw, "gif");
    NSLog(@"Going into ImageMagick stuff");
    for (UIImage *img in frames) {
        MagickWand *localWand = NewMagickWand();
        NSData *dataObj = UIImagePNGRepresentation(img);
        MagickReadImageBlob(localWand, [dataObj bytes], [dataObj length]);
        MagickSetImageDelay(localWand, 1);
        //        MagickSetCompression(localWand, JPEGCompression);
        //        MagickSetCompressionQuality(localWand, 0.5);
        MagickAddImage(mw, localWand);
        DestroyMagickWand(localWand);
    }
    MagickWand *newmw = NewMagickWand();
    newmw = MagickCoalesceImages(mw);
    size_t my_size;
    NSLog(@"This is the part that takes forever");
    unsigned char * my_image = MagickGetImagesBlob(newmw, &my_size);
    NSData *data = [[NSData alloc] initWithBytes:my_image length:my_size];
    free(my_image);
    DestroyMagickWand(mw);
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *path = [paths objectAtIndex:0];
    path = [NSString stringWithFormat:@"%@/animation.gif", path];
    NSLog(@"Going to write to file");
    
    [data writeToFile:path atomically:YES];
    NSLog(@"Wrote to file");
    
    NSURL *urlzor = [NSURL fileURLWithPath:path];
    NSLog(@"%@", urlzor);
    NSLog(@"%@", path);
}

//格式转化
- (void)compressToJPG {
    UIImage *imagezor = [[UIImage alloc] initWithContentsOfFile:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%d", 1] ofType:@"png"]];
    
    MagickWand *mw = NewMagickWand();
    MagickSetFormat(mw, "jpeg");
    NSLog(@"Going into ImageMagick stuff");
    MagickWand *localWand = NewMagickWand();
    NSData *dataObj = UIImagePNGRepresentation(imagezor);
    MagickReadImageBlob(localWand, [dataObj bytes], [dataObj length]);
    //        MagickSetImageDelay(localWand, 1);
    //        MagickSetCompression(localWand, JPEGCompression);
    MagickSetCompressionQuality(localWand, 0.5);
    MagickAddImage(mw, localWand);
    DestroyMagickWand(localWand);
    
    size_t my_size;
    unsigned char * my_image = MagickGetImagesBlob(mw, &my_size);
    NSData *data = [[NSData alloc] initWithBytes:my_image length:my_size];
    free(my_image);
    DestroyMagickWand(mw);
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *path = [paths objectAtIndex:0];
    path = [NSString stringWithFormat:@"%@/animation.jpg", path];
    
    [data writeToFile:path atomically:YES];
    
//    NSURL *urlzor = [NSURL fileURLWithPath:path];
}

//加密图片
-(void)EncipherImage{
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"1" ofType:@"png"];
    MagickWandGenesis();
    self.wand = NewMagickWand();
    
    // Create temporary file
    NSString *tempFilePath = [NSTemporaryDirectory()
                              stringByAppendingPathComponent:@"new.gif"];
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *path = [paths objectAtIndex:0];
    path = [NSString stringWithFormat:@"%@/animation.gif", path];
    
    // Read given image with C-string
    MagickReadImage(self.wand,
                    [path cStringUsingEncoding:NSASCIIStringEncoding]
                    );
    
    MagickWand *mw = NewMagickWand();
//    mw = MagickOptimizeImageLayers(self.wand);
//        MagickGaussianBlurImage(self.wand,20,1.5);
        MagickEncipherImage(self.wand, "123");
//     Monochrome image
//        MagickQuantizeImage(self.wand,2,GRAYColorspace,1,MagickFalse,MagickFalse);
    
    // Write to temporary file
    MagickWriteImages(mw,
                      [tempFilePath cStringUsingEncoding:NSASCIIStringEncoding]
                      ,MagickTrue);
    
    // Load UIImage from temporary file
    UIImage *imgObj = [UIImage imageWithContentsOfFile:tempFilePath];
    
    if (self.wand)
        self.wand = DestroyMagickWand(self.wand);
    MagickWandTerminus();
    
    // Display on device
 }

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
