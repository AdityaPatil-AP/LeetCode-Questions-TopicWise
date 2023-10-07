#import 
@interface Adder : NSObject {
    NSInteger t;}
- (id)initWithInitialNumber:(NSInteger)initialNumber;
- (void)addNumber:(NSInteger)newNumber;
- (NSInteger)total;
@end
@implementation Adder
- (id)initWithInitialNumber:(NSInteger)initial {
    t = initial;
    return self;}
- (void)addNumber:(NSInteger)n {
    t = t + n;}
- (NSInteger)total {
    return t;}
@end
int main(int argc, const char* argv[]){
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    Adder *add = [[Adder alloc]initWithInitialNumber:277];
    [add addNumber:6];
    [add addNumber:99];
    NSLog(@"The Total is %ld", [add total]);
    [pool drain];
    return 0;
}