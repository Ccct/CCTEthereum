//
//  TransferVC.m
//  CCTEthereum
//
//  Created by Helios on 2019/2/19.
//  Copyright © 2019 Helios. All rights reserved.
//

#import "TransferVC.h"
#import "CCTEtherLib.h"

@interface TransferVC ()

@end

@implementation TransferVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"转账";
}

- (IBAction)transferBtnAction:(id)sender {
    
    /**
     完整的 CCTEtherLib 代码，请加我的QQ：705356202
     **/
    
    [CCTEtherLib transferToAssress:@"" //收款地址
                             Money:@"" //转账金额
                             Token:@"" //eth填nil，其他代币填对应的token
                      DecimalCount:@"" //小数位数
                   currentKeyStore:@"" //付款钱包的KeyStore
                               pwd:@"" //付款钱包的密码
                          GasPrice:@"" //矿工费用，不填则自动获取
                          GasLimit:@"" //eth转账一般填21000  其他代币转账填60000   nil 默认 21000
                       Resultblock:^(NSString *hashStr, BOOL suc, CCTEtherError error) {
        
                           if(suc){
                               NSLog(@"成功！ 转账hash: %@",hashStr);
                           }else{
                               NSLog(@"失败！ %d",(short)error);
                           }
                          }];
}

@end
