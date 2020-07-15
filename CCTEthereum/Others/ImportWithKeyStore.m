//
//  ImportWithKeyStore.m
//  CCTEthereum
//
//  Created by Helios on 2019/2/18.
//  Copyright © 2019 Helios. All rights reserved.
//

#import "ImportWithKeyStore.h"
#import "CCTEtherLib.h"

@interface ImportWithKeyStore ()

@property (weak, nonatomic) IBOutlet UITextView *keyText;

@property (weak, nonatomic) IBOutlet UITextView *textV;

@end

@implementation ImportWithKeyStore

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"通过keystore导入钱包";
}

- (IBAction)importBtnAction:(id)sender {
    
    /**
     完整的 CCTEtherLib 代码，请加我的QQ：705356202
     **/
    
    if (self.keyText.text.length == 0){
        return;
    }
    
    [CCTEtherLib importWalletWithKeyStore:self.keyText.text pwd:@"12345678" resultblock:^(NSString *address, NSString *keyStore, NSString *mnemonicPhrase, NSString *privateKey, BOOL suc, CCTEtherError error) {

        if(suc){
            self.textV.text = [NSString stringWithFormat:@"【钱包地址address】%@\n\n【keyStore】%@\n\n【助记词mnemonicPhrase】%@\n\n【私钥privateKey】%@\n",address,keyStore,mnemonicPhrase,privateKey];
        }else{
            NSLog(@"导入失败  %ld",(long)error);
        }
    }];
}

@end
