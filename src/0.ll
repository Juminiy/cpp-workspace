; ModuleID = '0.c'
source_filename = "0.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @comp(i32 noundef %type, ptr noundef %a, ptr noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %type.addr = alloca i32, align 4
  %a.addr = alloca ptr, align 8
  %b.addr = alloca ptr, align 8
  %conv_a = alloca ptr, align 8
  %conv_b = alloca ptr, align 8
  %conv_a11 = alloca ptr, align 8
  %conv_b12 = alloca ptr, align 8
  %comp_res = alloca float, align 4
  store i32 %type, ptr %type.addr, align 4
  store ptr %a, ptr %a.addr, align 8
  store ptr %b, ptr %b.addr, align 8
  %0 = load i32, ptr %type.addr, align 4
  switch i32 %0, label %sw.default [
    i32 0, label %sw.bb
    i32 1, label %sw.bb1
    i32 2, label %sw.bb2
    i32 3, label %sw.bb3
    i32 4, label %sw.bb4
    i32 5, label %sw.bb5
    i32 6, label %sw.bb6
    i32 7, label %sw.bb7
    i32 8, label %sw.bb8
    i32 9, label %sw.bb9
    i32 10, label %sw.bb10
    i32 11, label %sw.bb18
    i32 12, label %sw.bb19
  ]

sw.bb:                                            ; preds = %entry
  br label %sw.epilog

sw.bb1:                                           ; preds = %entry
  br label %sw.epilog

sw.bb2:                                           ; preds = %entry
  br label %sw.epilog

sw.bb3:                                           ; preds = %entry
  br label %sw.epilog

sw.bb4:                                           ; preds = %entry
  br label %sw.epilog

sw.bb5:                                           ; preds = %entry
  %1 = load ptr, ptr %a.addr, align 8
  store ptr %1, ptr %conv_a, align 8
  %2 = load ptr, ptr %b.addr, align 8
  store ptr %2, ptr %conv_b, align 8
  %3 = load ptr, ptr %conv_a, align 8
  %4 = load i32, ptr %3, align 4
  %5 = load ptr, ptr %conv_b, align 8
  %6 = load i32, ptr %5, align 4
  %sub = sub nsw i32 %4, %6
  store i32 %sub, ptr %retval, align 4
  br label %return

sw.bb6:                                           ; preds = %entry
  br label %sw.epilog

sw.bb7:                                           ; preds = %entry
  br label %sw.epilog

sw.bb8:                                           ; preds = %entry
  br label %sw.epilog

sw.bb9:                                           ; preds = %entry
  br label %sw.epilog

sw.bb10:                                          ; preds = %entry
  %7 = load ptr, ptr %a.addr, align 8
  store ptr %7, ptr %conv_a11, align 8
  %8 = load ptr, ptr %b.addr, align 8
  store ptr %8, ptr %conv_b12, align 8
  %9 = load ptr, ptr %conv_a11, align 8
  %10 = load float, ptr %9, align 4
  %11 = load ptr, ptr %conv_b12, align 8
  %12 = load float, ptr %11, align 4
  %sub13 = fsub float %10, %12
  store float %sub13, ptr %comp_res, align 4
  %13 = load float, ptr %comp_res, align 4
  %conv = fpext float %13 to double
  %cmp = fcmp olt double %conv, 1.000000e-05
  br i1 %cmp, label %lor.end, label %lor.rhs

lor.rhs:                                          ; preds = %sw.bb10
  %14 = load float, ptr %comp_res, align 4
  %conv15 = fpext float %14 to double
  %cmp16 = fcmp ogt double %conv15, -1.000000e-05
  br label %lor.end

lor.end:                                          ; preds = %lor.rhs, %sw.bb10
  %15 = phi i1 [ true, %sw.bb10 ], [ %cmp16, %lor.rhs ]
  %lor.ext = zext i1 %15 to i32
  store i32 %lor.ext, ptr %retval, align 4
  br label %return

sw.bb18:                                          ; preds = %entry
  br label %sw.epilog

sw.bb19:                                          ; preds = %entry
  br label %sw.epilog

sw.default:                                       ; preds = %entry
  br label %sw.epilog

sw.epilog:                                        ; preds = %sw.default, %sw.bb19, %sw.bb18, %sw.bb9, %sw.bb8, %sw.bb7, %sw.bb6, %sw.bb4, %sw.bb3, %sw.bb2, %sw.bb1, %sw.bb
  store i32 0, ptr %retval, align 4
  br label %return

return:                                           ; preds = %sw.epilog, %lor.end, %sw.bb5
  %16 = load i32, ptr %retval, align 4
  ret i32 %16
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i8 @tolower_(i8 noundef signext %c) #0 {
entry:
  %c.addr = alloca i8, align 1
  store i8 %c, ptr %c.addr, align 1
  %0 = load i8, ptr %c.addr, align 1
  %conv = sext i8 %0 to i32
  %cmp = icmp sge i32 %conv, 65
  br i1 %cmp, label %land.lhs.true, label %cond.false

land.lhs.true:                                    ; preds = %entry
  %1 = load i8, ptr %c.addr, align 1
  %conv2 = sext i8 %1 to i32
  %cmp3 = icmp sle i32 %conv2, 90
  br i1 %cmp3, label %cond.true, label %cond.false

cond.true:                                        ; preds = %land.lhs.true
  %2 = load i8, ptr %c.addr, align 1
  %conv5 = sext i8 %2 to i32
  %3 = load i8, ptr %c.addr, align 1
  %conv6 = sext i8 %3 to i32
  %sub = sub nsw i32 %conv6, 65
  %cmp7 = icmp ult i32 %sub, 26
  %conv8 = zext i1 %cmp7 to i32
  %shl = shl i32 %conv8, 5
  %add = add nsw i32 %conv5, %shl
  br label %cond.end

cond.false:                                       ; preds = %land.lhs.true, %entry
  %4 = load i8, ptr %c.addr, align 1
  %conv9 = sext i8 %4 to i32
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %add, %cond.true ], [ %conv9, %cond.false ]
  %conv10 = trunc i32 %cond to i8
  ret i8 %conv10
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.0"}
