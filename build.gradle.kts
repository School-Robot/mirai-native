plugins {
    id("me.him188.maven-central-publish") version "1.0.0-dev-3"

    kotlin("jvm") version "1.7.20"
    kotlin("plugin.serialization") version "1.7.20"

    id("net.mamoe.mirai-console") version "2.14.0"
}

group = "org.itxtech"
version = "2.0.1"
description = "强大的 mirai 原生插件加载器。"


repositories {
    mavenCentral()
}

dependencies {
    implementation("io.ktor:ktor-client-okhttp:2.2.3"){
        exclude(group = "org.jetbrains.kotlin")
        exclude(group = "org.jetbrains.kotlinx")
        exclude(group = "org.slf4j")
    }
    compileOnly("org.jetbrains.kotlinx:atomicfu:0.18.4")
    implementation("com.squareup.okhttp3:okhttp:4.10.0"){
        exclude(group = "org.jetbrains.kotlin")
        exclude(group = "org.jetbrains.kotlinx")
        exclude(group = "org.slf4j")
    }
}

mavenCentralPublish {
    singleDevGithubProject("iTXTech", "mirai-native")
    licenseAGplV3()
    useCentralS01()
}

tasks.named<Jar>("jar") {
    manifest {
        attributes["Name"] = "iTXTech MiraiNative"
        attributes["Revision"] = Runtime.getRuntime().exec("git rev-parse --short HEAD")
            .inputStream.bufferedReader().readText().trim()
    }
}

mirai{
    jvmTarget = org.gradle.api.JavaVersion.VERSION_11
}
