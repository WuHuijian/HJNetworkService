//
//  HJDownloadModel.h
//  HJNetworkService
//
//  Created by WHJ on 16/7/5.
//  Copyright © 2016年 WHJ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class HJDownloadOperation;
@class HJDownloadModel;


typedef NS_ENUM(NSUInteger, HJDownloadStatus) {
    kHJDownloadStatus_None,
    kHJDownloadStatus_Running,
    kHJDownloadStatus_suspended,
    kHJDownloadStatusCompleted = 3,  // 下载完成
    kHJDownloadStatusFailed  = 4,    // 下载失败
    kHJDownloadStatusWaiting = 5,   // 等待下载
    kHJDownloadStatusCancel = 6      // 取消下载
};


typedef void(^DownloadStatusChanged)(HJDownloadModel *downloadModel);

typedef void(^DownloadProgressChanged)(HJDownloadModel *downloadModel);



@interface HJDownloadModel : NSObject


@property (nonatomic ,copy) NSString * urlString;

@property (nonatomic, copy) NSString * fileName;

@property (nonatomic, copy) NSString * fileFormat;

@property (nonatomic, copy) NSString * destinationPath;//文件存放地址

@property (nonatomic, strong) HJDownloadOperation * operation;//下载操作

@property (nonatomic, strong) NSData * resumeData;//下载数据

@property (nonatomic, copy) NSString * resumeDataPath;//reusmeData文件路径

@property (nonatomic, copy) NSString * tmpFilePath;//文件暂停时所保存路径

@property (nonatomic, assign) CGFloat progress;

@property (nonatomic, assign) HJDownloadStatus status;

@property (nonatomic, copy) NSString * statusText;

@property (nonatomic, copy) NSString * completeTime;//下载完成时间

@property (nonatomic, copy) DownloadStatusChanged statusChanged;//状态改变回调

@property (nonatomic, copy) DownloadProgressChanged progressChanged;//进度改变回调

@property (nonatomic, assign) BOOL isLast;//数组最后一个模型


@end
